import numpy as np

def mse(y, y_hat):
    tmp = 0
    for arg, arg1 in zip(y_hat, y):
        tmp += (arg - arg1) ** 2
    # tmp = tmp ** 2
    tmp = tmp / len(y)
    return tmp

def main():
    X = np.array([0, 15, -9, 7, 12, 3, -21])
    Y = np.array([2, 14, -13, 5, 12, 4, -19])
    res = mse(X, Y)
    print(res)
    res = mse(X, X)
    print(res)

if __name__ == "__main__":
    main()