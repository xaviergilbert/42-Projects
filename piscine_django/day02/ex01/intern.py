#Checker pour l'exception 

class Intern:
    def __init__(self, str = "My name? I'm nobody, an intern, I have no name."):
        self.Name = str


    def __str__(self):
        return self.Name

    class Coffee:
        def __str__(self):
            return "This is the worst coffee you ever tasted."

        def work(self):
            raise Exception("I'm just an intern, I can't do that...")

        def make_coffee(self):
            return self

def main():
    try:
        mark = Intern("Mark")
        inconnu = Intern()
        print(mark)
        print(inconnu)
        print(mark.Coffee().make_coffee())
        print(inconnu.Coffee().work())
    except Exception as e:
        print(e)

if __name__ == "__main__":
    main()