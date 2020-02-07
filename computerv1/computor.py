import sys
from polynome_class import polynome_class

def calculerDelta(a,b,c):
   return b*b-4*a*c

def main(*argv):
    ma_class = polynome_class(sys.argv[1])
    print(ma_class.tab)
    # print("ici")
    # print("la")
    exit

if __name__ == "__main__":
    main(sys.argv)
    # print("la")