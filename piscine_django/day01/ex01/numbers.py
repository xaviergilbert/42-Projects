

def main():
    content = open('numbers.txt', 'r').read()
    i = 0
    content_length = len(content)
    while i < content_length:
        count = 0
        while i < content_length and content[i] >= "0" and content[i] <= "9":
            count += 1
            i += 1
        if (count > 0):
            print(content[i - count:i])
        i += 1

if __name__ == "__main__":
    main()