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
def main():
    X = np.array([0, 15, -9, 7, 12, 3, -21])
    print(mean(X))
    print(mean(X ** 2))
    #135.57142857142858
if __name__ == "__main__":
    main()