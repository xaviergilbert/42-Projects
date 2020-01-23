import numpy as np

def mean(x):
    """Computes the mean of a non-empty numpy.ndarray, using a for-loop.
    Args:
    x: has to be an numpy.ndarray, a vector.
    Returns:
    The mean as a float.
    None if x is an empty numpy.ndarray.
    Raises:
    This function should not raise any Exception.
    """
    if len(x) == 0:
        return (None)
    tmp = 0.0
    for arg in x:
        tmp += arg
    tmp = tmp / len(x)
    tmp = mean(x)
    return(tmp)

def linear_mse(x, y, theta):
    tmp = x.dot(theta)
    print(tmp)
    print(y)
    tmp = np.mean(tmp, y) ** 2
    return tmp

def main():
    X = np.array([
    [ -6, -7, -9],
        [ 13, -2, 14],
        [ -7, 14, -1],
        [ -8, -4, 6],
        [ -5, -9, 6],
        [ 1, -5, 11],
        [ 9, -11, 8]])
    Y = np.array([2, 14, -13, 5, 12, 4, -19])
    Z = np.array([3, 0.5, -6])
    res = linear_mse(X, Y, Z)
    print("\nresultat :")
    print(res)
    W = np.array([0, 0, 0])
    res = linear_mse(X, Y, W)
    print("\nresultat :")
    print(res)

if __name__ == "__main__":
    main()