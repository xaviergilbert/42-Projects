import sys
import antigravity

#fuck this shit

def main():
    i = 1
    input = []
    while i < len(sys.argv):
        # print(sys.argv[i])
        input.append(float(sys.argv[i]))
        i += 1
    print(input)

if __name__ == "__main__":
    main()