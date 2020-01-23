from termcolor import colored


class CsvReader():
    def __init__(self, name, sep=',', header=False, skip_top=0, skip_bottom=0):
        self.sep = sep
        self.header = header
        self.skip_top = skip_top
        self.skip_bottom = skip_bottom
        self.filename = name

    def __enter__(self):
        try:
            self.f = open(self.filename, 'r')
        except IOError:
            print("File not found")
            exit()
        self.content = self.f.read()
        return self

    def __exit__(self, type, value, traceback):
        self.f.close()
    
    def getdata(self):
        index = 0
        count_lines = 0
        while (count_lines < self.skip_top):
            while (self.content[index]):
                if self.content == '\n':
                    count_lines += 1
                index += 1
        if self.header == True:
            while (index < len(self.content) and self.content[index] != '\n'):
                index += 1
            index += 1
        start = index
        line = self.content[start:].replace(" ", "").replace('"', "").split('\n')
        lst = []
        for elem in line:
            lst.append(elem.split(','))
        return lst
    
    def getheader(self):
        if self.header == False:
            return "Error"
        index = 0
        count_lines = 0
        while (count_lines < self.skip_top):
            while (self.content[index]):
                if self.content == "\n":
                    count_lines += 1
                index += 1
        start = index
        while (self.content[index] != "\n"):
            index += 1
        header = self.content[start:index].replace(" ", "").replace('"', "").split(',')
        return header
    


def good():
    with CsvReader('good.csv', ",", True) as file:
        data = file.getdata()
        header = file.getheader()
    print("Header : \n", header, "\n")
    print("Data : \n", data)

def bad():
    with CsvReader('bad.csv') as file:
        if file == None:
            print("File is corrupted")

if __name__ == "__main__":
    good()
    bad()