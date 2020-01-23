import numpy as np

def vec_mse(y, y_hat):
    return np.sum((y_hat - y) ** 2) / len(y)

def main():
    X = np.array([0, 15, -9, 7, 12, 3, -21])
    Y = np.array([2, 14, -13, 5, 12, 4, -19])
    res = vec_mse(X, Y)
    print(res)
    res = vec_mse(X, X)
    print(res)

if __name__ == "__main__":
    main()