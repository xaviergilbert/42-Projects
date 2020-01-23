class Vector():
    def __init__(self, arg):
        if type(arg) == tuple:
            self.arg_tuple(arg)
        elif type(arg) == list:
            self.arg_liste(arg)
        elif type(arg) == int:
            self.arg_int(arg)
        else:
            print("error")
    def arg_tuple(self, arg):
        self.values = []
        number = arg[0]
        while number < arg[1]:
            self.values.append(float(number))
            number += 1
        self.size = len(self.values)
    def arg_liste(self, arg):
        self.values = []
        for number in arg:
            self.values.append(float(number))
        self.size = len(self.values)
    def arg_int(self, arg):
        self.values = []
        for i in range(arg):
            self.values.append(float(i))
        self.size = arg
    def __mul__(self, number):
        if type(number) == Vector:
            for i in range(self.size):
                self.values[i] *= number.values[i]
            return self.values
        for i in range(self.size):
            self.values[i] *= number
        return self.values
    def __rmul__(self, number):
        if number == 0:
            return self
        else:
            return self.__mul__(number)
    def __add__(self, number):
        for i in range(self.size):
            self.values[i] += number
        return self.values        
    def __radd__(self, number):
        if number == 0:
            return self
        else:
            return self.__add__(number)
    def __sub__(self, number):
        for i in range(self.size):
            self.values[i] -= number
        return self.values      
    def __rsub__(self, number):
        if number == 0:
            return self
        else:
            return self.__sub__(number)
    def __truediv__(self, number):
        for i in range(self.size):
            self.values[i] /= number
        return self.values    
# not true but osef
    def __rtruediv__(self, number):
        if number == 0:
            return self
        else:
            return self.__truediv__(number)
v1 = Vector((10, 15))
print(v1 * v1)