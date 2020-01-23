import numpy as np

def dot(x,y):
    """Computes the dot product of two non-empty numpy.ndarray, using a
for-loop. The two arrays must have the same dimensions.
    Args:
    x: has to be an numpy.ndarray, a vector.
    y: has to be an numpy.ndarray, a vector.
    Returns:
    The dot product of the two vectors as a float.
    None if x or y are empty numpy.ndarray.
    None if x and y does not share the same dimensions.
    Raises:
    This function should not raise any Exception.
    """
    f = lambda f, r : f * r
    tmp = 0.0
    for arg, arg1 in zip(x, y):
        tmp += f(arg , arg1)
    if (len(x) == 0): 
        print("bug")
        return(None)
    return(tmp)
    
def main():
    X = np.array([0, 15, -9, 7, 12, 3, -21])
    Y = np.array([2, 14, -13, 5, 12, 4, -19])
    print(dot(X, Y))
    print(np.dot(X, Y))
    print(dot(X, X))
    print(np.dot(X, X))
    print(dot(Y, Y))
    print(np.dot(Y, Y))
    
if __name__ == "__main__":
    main()