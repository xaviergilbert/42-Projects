import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import csv
from mylinearregression import MyLinearRegression as MyLR


def main():
    data = pd.read_csv("spacecraft_data.csv")
    X = np.array(data[['Age','Thrust_power','Terameters']])
    Y = np.array(data[['Sell_price']])
    print("X : \n", X)
    print("Y : \n", Y)
    my_lreg = MyLR([1.0, 1.0, 1.0, 1.0])
    print("mse : \n", my_lreg.mse_(my_lreg.predict_(X),Y))
    # fit = my_lreg.fit_(X, Y, alpha = 1e-4, n_cycle = 600000)
    my_lreg = MyLR([359.8952751, -23.43288818, 5.76394882, -2.62662245])
    print("new theta : \n", my_lreg.theta)
    print("\npredict : \n", my_lreg.predict_(X))
    print("\ncost elem : \n", my_lreg.cost_elem_(X,Y))
    print("\ncost : ", my_lreg.cost_(X,Y))
    print("mse : \n", my_lreg.mse_(my_lreg.predict_(X),Y))

    # plot
    predict = my_lreg.predict_(X)
    age = np.array(X[: , :1])
    plt.plot(age, Y, 'bo', age, predict, 'go')
    plt.title('Prix en fonction de l\'age')
    plt.show()

    thrust_power = np.array(X[: , 1:2])
    plt.plot(thrust_power, Y, 'bo', thrust_power, predict, 'go')
    plt.title('Prix en fonction de thrust power')
    plt.show()

    tmeters = np.array(X[:, 2:])
    plt.plot(tmeters, Y, 'bo', tmeters, predict, 'go')
    plt.title('Prix en fonction des Tmeters du spacecraft')
    plt.show()


if __name__ == "__main__":
    main()