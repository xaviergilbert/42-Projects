import sys

class settings:
    def __init__(self):
        self.variables = {}
        self.f = open("settings.py", "r")
        self.content = self.f.readlines()
        for line in self.content:
            self.put_variable_in_dic(line)

    def put_variable_in_dic(self, line):
        line = line.replace("\n", "")
        line = line.replace("\"", "")
        split_line = line.split("=")
        split_line[0] = split_line[0].strip()
        split_line[1] = split_line[1].strip() 
        self.variables[split_line[0]] = split_line[1]

def get_variable(my_settings, str):
    return my_settings.variables[str[1:-1]]

def write_html(f, my_settings):
    html = open(sys.argv[1].split(".")[0] + ".html", "w")
    content = f.readlines()
    for line in content:
        length = len(line)
        i = 0
        while i < length:
            index = 0
            while i < length and line[i] != "{":
                i += 1
            if i < length and line[i] == "{":
                while i + index < length and line[i + index] != "}":
                    index += 1
                if i + index < length and line[i + index] == "}":
                    var = get_variable(my_settings, line[i: i + index + 1])
                    line = line.replace(line[i: i + index + 1], var)
                    i = -1    
            i += 1
            length = len(line)
        html.write(line)
    


def main():
    if len(sys.argv) == 2:
        my_settings = settings()
        # print(my_settings.variables)
        try:
            f = open(sys.argv[1], "r")
        except:
            print("Le fichier n'existe pas")
            exit()
        if sys.argv[1].split(".")[1] != "template":
            print("Le fichier envoye n'est pas au bon format")
            exit()
        write_html(f, my_settings)

if __name__ == "__main__": 
    main()