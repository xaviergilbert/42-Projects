class HotBeverages:
    def __init__(self):
        self.price = 0.30
        self.name = "hot beverage"

    def description(self):
        return "JUst some hot water in a cup."

    def __str__(self):
        return "name : " + self.name \
        + "\nprice : " + str(self.price) \
        + "\ndescription : " + self.description()

class Coffee(HotBeverages):
    def __init__(self):
        self.price = 0.40
        self.name = "coffee"

    def description(self):
        return "A coffee, to stay awake."

class Tea(HotBeverages):
    def __init__(self):
        self.price = 0.30
        self.name = "tea"

    def description(self):
        return "Just some hot water in a cup."

class Chocolate(HotBeverages):
    def __init__(self):
        self.price = 0.50
        self.name = "chocolate"

    def description(self):
        return "Chocolate, sweet chcolate..."

class Cappuccino(HotBeverages):
    def __init__(self):
        self.price = 0.45
        self.name = "cappuccino"

    def description(self):
        return "Un po' di Italia nella sua tazza!"

def main():
    class_beverage = HotBeverages()
    print(class_beverage)
    class_coffee = Coffee()
    print(class_coffee)
    class_tea = Tea()
    print(class_tea)
    class_chocolate = Chocolate()
    print(class_chocolate)
    class_cappuccino = Cappuccino()
    print(class_cappuccino)

if __name__ == "__main__":
    main()
