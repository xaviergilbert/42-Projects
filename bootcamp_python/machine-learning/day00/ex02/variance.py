import numpy as np

def variance(x):
    """Computes the variance of a non-empty numpy.ndarray, using a for-loop.
    Args:
     x: has to be an numpy.ndarray, a vector.
    Returns:
     The variance as a float.
     None if x is an empty numpy.ndarray.
    Raises:
     This function should not raise any Exception.
    """
    if len(x) == 0:
        return (None)
    moy = 0.0
    for arg in x:
        moy += arg
    moy = moy / len(x)
    tmp = 0.0
    for arg in x:
        tmp += (moy - arg)**2
    tmp = tmp / len(x)
    return (tmp)
def main():
    X = np.array([0, 15, -9, 7, 12, 3, -21])
    print(variance(X))
    print(np.var(X))
    print(variance(X/2))
    print(np.var(X/2))
if __name__ == "__main__":
    main()