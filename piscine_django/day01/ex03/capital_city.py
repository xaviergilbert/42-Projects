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



def main():
    # states, capital_cities = initiate_dict()
    if len(sys.argv) == 2:
        ma_classe = US_states()
        ret = ma_classe.find_cap(sys.argv[1])
    if ret != None:
        print(ret)

if __name__ == "__main__":
    main()