import random
from beverages import *

class CoffeeMachine:
    def __init__(self):
        self.use = 9

    class EmptyCup(HotBeverages):
        def __init__(self):
            self.name = "empty cup"
            self.price = 0.90
        
        def description(self):
            return "An empty cup ?! Gimme my money back!"

    class BrokenMachineException(Exception):
        def __init__(self, message = "This coffee machine has to be repaired."):
            Exception.__init__(self, message)

    def repair(self):
        self.use = 0
        print("Machine has been repaired")

    def serve(self, produit):
        if self.use >= 10:
            raise self.BrokenMachineException()
        else:
            if random.random() < .5:
                self.use += 1
                return produit
            else:
                return self.EmptyCup()

def main():
    machine = CoffeeMachine()
    hotbeverages = HotBeverages()
    coffee = Coffee()
    tea = Tea()
    chocolate = Chocolate()
    cappuccino = Cappuccino()
    # i = 0
    while True:
        try:
            print("Choices :")
            print("1 : HotBeverages")
            print("2 : Coffee")
            print("3: Tea")
            print("4: Chocolate")
            print("5: Cappuccino")
            print("Other number to exit")
            number = input("Your choice : ")
            while number.isnumeric() == False:
                print("Enter a numeric value please")
                number = input("Your choice : ")
            number = int(number)
            if number == 1:
                object = machine.serve(hotbeverages)
            elif number == 2:
                object = machine.serve(coffee)
            elif number == 3:
                object = machine.serve(tea)
            elif number == 4:
                object = machine.serve(chocolate)
            elif number == 5:
                object = machine.serve(cappuccino)
            else:
                break
            print(type(object))
            # if type(object) == class:
                # print("ici")
            # print(object.name)
            print(machine.use)
        except Exception as e:
            print(e)
            machine.repair()

if __name__ == "__main__":
    main()