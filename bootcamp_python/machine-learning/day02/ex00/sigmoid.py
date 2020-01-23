import numpy as np 
import math

def sigmoid_(x):
    """
        Compute the sigmoid of a scalar or a list.
        Args:
            x: a scalar or list
        Returns:
            The sigmoid value as a scalar or list.
            None on any error.
        Raises:
            This function should not raise any Exception.
    """
    if type(x) == list:
        tab = []
        for elem in x:
            tab.append(1 / (1 + math.exp(-elem)))
        return tab
    return 1 / (1 + math.exp(-x))

def main():
    X = -4
    print("res : ", sigmoid_(X))
    X = 2
    print("res : ", sigmoid_(X))
    X = [-4, 2, 0]
    print("res : ", sigmoid_(X))

if __name__ == "__main__":
    main()