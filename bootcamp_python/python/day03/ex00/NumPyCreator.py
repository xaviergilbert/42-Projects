import numpy as np

class NumPyCreator:

    def from_list(self, lst):
        """ takes in a list and returns its corresponding NumPy array """
        return np.array(lst)
        

    def from_tuple(self, tpl):
        """ takes in a tuple and returns its corresponding NumPy array """
        return np.asarray(tpl)

    def from_iterable(self, itr):
        """ takes in an iterable and returns an array which contains all of its elements """
        return np.asarray(itr)

    def from_shape(self, shape, value = 0):
        """ returns an array filled with the same value """
        return np.full(shape, value)

    def random(self, shape):
        """ returns an array filled with random values """
        return np.random.rand(shape[0], shape[1])

    def identity(self, n):
        """ returns an array representing the identity matrix of size n """
        return np.identity(n)


if __name__ == "__main__":
    npc = NumPyCreator()
    print(npc.from_list([[1,2,3],[6,3,4]]))
    print(npc.from_tuple(("a", "b", "c")))