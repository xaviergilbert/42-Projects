import datetime

def options(txt,option):
    #random forbidden
    if option == "shuffle":
        answer = []
        for element in txt:
            answer.append(element)
            if datetime.datetime.now().microsecond % 2 == 1:
                answer.reverse()
        return answer
    elif option == "unique":
        txt.sort()
        i = 0
        while i < len(txt) - 1:
            if txt[i] == txt[i + 1]:
                del txt[i]
            else:
                i += 1
        return txt
    elif option == "ordered":
        return sorted(txt)
    elif option == None:
        return txt
    else:
        print("ERROR")
        exit()
def generator(text, sep=" ", option=None):
    if type(text) != str:
        print("ERROR")
        exit()
    answer = options(text.split(sep),option)
    for element in answer:
        yield element
generateur = generator("1,2,3,4,5,6,7,8,9", ',', "shuffle")
print("ceci est un generateur")
for txt in generateur:
    print(txt)