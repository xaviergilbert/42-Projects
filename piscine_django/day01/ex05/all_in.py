import sys

class US_states:
    def __init__(self):
        self.states = {
            "Oregon": "OR",
            "Alabama": "AL",
            "New Jersey": "NJ",
            "Colorado": "CO"
        }

        self.capital_cities = {
            "OR": "Salem",
            "AL": "MOntgomery",
            "NJ": "Trenton",
            "CO": "Denver"
        }
    
    def find_cap(self, state):
        try:
            self.states[state]
            return self.capital_cities[self.states[state]]
        except:
            pass
    
    def find_state(self, cap):
        for key, value in self.capital_cities.items(): 
            if cap == value: 
                clef = key 
                for key, value in self.states.items(): 
                    if clef == value: 
                        return key
    
    def print_cap_and_state(self, word):
        cap = self.find_cap(word)
        state = self.find_state(word)
        if cap == None and state == None:
            print(word, "is neither a capital city nor a state")
        elif cap == None:
            print(word, "is the capital of", state)
        else:
            print(cap, "is the capital of", word)

def main():
    if len(sys.argv) == 2:
        liste = sys.argv[1].split(",")
        i = 0
        while i < len(liste):
            liste[i] = liste[i].strip().title()
            if liste[i] == "":
                liste.remove(liste[i])
                i -= 1
            i += 1
        print(liste)
        ma_classe = US_states()
    for elem in liste:
        ma_classe.print_cap_and_state(elem)

if __name__ == "__main__":
    main()