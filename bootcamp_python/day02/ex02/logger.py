import time
from random import randint

class CoffeeMachine():
    water_level = 100

    def log(func):

        def wrapper(*args, **kwargs):
            filename = "machine.log"
            f = open(filename, 'a')
            f.write("(cmaxime)Running: ")
            start_time = float(time.time() * 1000)
            function_name = func.__name__.replace("_", " ").title()
            f.write(function_name)
            result = func(*args, **kwargs)
            time_diff = round(float(time.time() * 1000 - start_time), 3)
            f.write(" [ exec-time = " + str(time_diff) + " ms ]\n")
            return result
        return wrapper

    @log
    def start_machine(self):
        if self.water_level > 20:
            return True
        else:
            print("Please add water!")
            return False

    @log
    def boil_water(self):
        return "boiling..."

    @log
    def make_coffee(self):
        if self.start_machine():
            for _ in range(20):
                time.sleep(0.1)
                self.water_level -= 1
            print(self.boil_water())
            print("Coffee is ready!")

    @log
    def add_water(self, water_level):
        time.sleep(randint(1, 5))
        self.water_level += water_level
        print("Blub blub blub...")

if __name__ == "__main__":
    machine = CoffeeMachine()
    for i in range(0, 5):
        machine.make_coffee()
    machine.make_coffee()
    machine.add_water(70)