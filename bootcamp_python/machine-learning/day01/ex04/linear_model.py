import numpy as np
import matplotlib.pyplot as plt
from mylinearregression import MyLinearRegression
import csv


def main():
    with open("are_blue_pills_magics.csv", 'r') as f:
        tab = list(csv.reader(f, delimiter=","))
    tab = np.array(tab[1:], dtype=np.float)
    tab = np.delete(tab, 0, 1)
    X = np.split(tab, 2, 1)[0]
    Y = np.split(tab, 2, 1)[1]
    print(X.shape)
    print(tab)
    print("X : \n", X)
    print("Y : \n", Y)
    theta = np.zeros(X.shape[1] + 1)
    theta = np.split(theta, X.shape[1] + 1, 0)
    print("theta : \n", theta)
    mylr = MyLinearRegression(theta)
    mylr = MyLinearRegression(np.array([[89.11302971], [-9.00731543]]))
    # mylr.fit_(X, Y, alpha = 1.6e-4, n_cycle=2000)
    print("\nfit new theta: \n", mylr.theta)
    predict = mylr.predict_(X)
    print("\npredict : \n", predict)
    print("\ncost elem : \n", mylr.cost_elem_(X,Y))
    print("\ncost : ", mylr.cost_(X,Y))
    # mylr.fit_(X, Y, alpha = 1.6e-4, n_cycle=200000)
    # print("\nfit new theta: \n", mylr.theta)
    print("mse : ", mylr.mse_(predict, Y))
    plt.plot(X, Y, 'bo', X, mylr.predict_(X), 'go', X, mylr.predict_(X), 'g--')
    plt.show()
    # plt.plot(X, Y, mylr.theta[1:], mylr.cost_(X,Y), 'g')
    # plt.xlim(-14, -4)
    # plt.ylim(30, 80)
    plt.show()

if __name__ == "__main__":
    main()