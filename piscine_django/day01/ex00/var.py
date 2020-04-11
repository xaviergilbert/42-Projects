
def my_var():
    print("42 est de type", type(42))
    print("42 est de type", type("42"))
    print("quarante-deux est de type", type("quarante-deux"))
    print("42.0 est de type", type(42.0))
    print("True est de type", type(True))
    print("[42] est de type", type([42]))
    print("{42: 42 est de type", type({42: 42}))
    print("(42, ) est de type", type((42, )))
    print("set() est de type", type(set()))

if __name__ == "__main__":
    my_var()