class ObjectC(object):
    def __init__(self):
        pass

def what_are_the_vars(*args, **kwargs):
    """Your code"""
    obj = ObjectC()
    index = 0
    for arg in args:
        attribut = "var_" + str(index)
        setattr(obj, attribut, arg)
        index += 1
    attribut = []
    for key in kwargs:
        attribut.append(key)
    value = []
    for valeur in kwargs.values():
        value.append(valeur)
    index = 0
    while index < len(attribut):
        for attr in dir(obj):
            if attr == attribut[index]:
                exit("Error\nend")
        setattr(obj, attribut[index], value[index])
        index += 1
    return obj

def doom_printer(obj):
    if obj is None:
        print("ERROR")
        print("end")
        return
    for attr in dir(obj):
        if attr[0] != '_':
            value = getattr(obj, attr)
            print("{}: {}".format(attr, value))
    print("end")

def main():
    obj = what_are_the_vars(7)
    doom_printer(obj)
    obj = what_are_the_vars("ft_lol", "Hi")
    doom_printer(obj)
    obj = what_are_the_vars()
    doom_printer(obj)
    obj = what_are_the_vars(12, "Yes", [0, 0, 0], a=10, hello="world")
    doom_printer(obj)
    obj = what_are_the_vars(42, a=10, var_0="world")
    doom_printer(obj)

if __name__ == "__main__":
    main()