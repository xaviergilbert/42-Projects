import numpy as np

class MyLinearRegression():
    """
    Description:
        My personnal linear regression class to fit like a boss.
    """

    def __init__(self, theta):
        """
            Description:
                generator of the class, initialize self.
            Args:
                theta: has to be a list or a numpy array, it is a vector of dimension (number of features + 1, 1).
            Raises:
                This method should noot raise any Exception.
        """
        self.theta = np.array(theta)

    def predict_(self, X):
        tab = []
        for j in range(X.shape[0]):
            i = 0
            tmp = 0
            while i < X.shape[1] + 1:
                if i == 0:
                    tmp = 1 * self.theta[i]
                else:
                    tmp += X[j][i - 1] * self.theta[i]
                i += 1
            tab.append(tmp)
        tab = np.array(tab)
        return tab

    def cost_elem_(self, X, Y):
        J_elem = self.predict_(X)
        J_elem = ((J_elem - Y) ** 2) / (2 * X.shape[0])
        return J_elem

    def cost_(self, X, Y):
        J_value = sum(self.cost_elem_(X, Y))
        return J_value

    def fit_(self, X, Y, alpha = 0.005, n_cycle = 1000):
        n = float(len(X))
        n = X.shape[0] * X.shape[1]
        for i in range(n_cycle): 
            Y_pred = np.reshape(self.predict_(X), np.shape(Y))
            D_m = (-2/n) * sum(X * (Y - Y_pred))  # Derivative wrt m
            D_c = (-2/n) * sum(Y - Y_pred)  # Derivative wrt c
            self.theta[0] = self.theta[0] - alpha * D_c
            self.theta[1:] = self.theta[1:] - alpha * np.reshape(D_m, (np.shape(self.theta[1:])))

    def mse_(self, y, y_hat):
        tmp = 0
        for arg, arg1 in zip(y_hat, y):
            tmp += (arg - arg1) ** 2
        tmp = tmp / len(y)
        return tmp

def main():
    X = np.array([[1., 1., 2., 3.], [5., 8., 13., 21.], [34., 55., 89., 144.]])
    Y = np.array([[23.], [48.], [218.]])
    mylr = MyLinearRegression([[1.], [1.], [1.], [1.], [1]])
    print("\npredict : ", mylr.predict_(X))
    print("\ncost elem : ", mylr.cost_elem_(X,Y))
    print("\ncost : ", mylr.cost_(X,Y))
    mylr.fit_(X, Y, alpha = 1.6e-4, n_cycle=200000)
    print("\nfit new theta: ", mylr.theta)
    print("\nfit : ", mylr.predict_(X))
    print("\ncost elem : ", mylr.cost_elem_(X,Y))
    print("\ncost : ", mylr.cost_(X,Y))

if __name__ == "__main__":
    main()