import numpy as np 

class MyRidge(ParentClass):
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
    
    def get_params_():
        pass

    def set_params_():
        pass

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

    def fit_(self, lambda=1.0, max_iter=1000, tol=0.001):
    """
        Fit the linear model by performing Ridge regression (Tikhonov
            regularization).
        Args:
            lambda: has to be a float. max_iter: has to be integer.
            tol: has to be float.
        Returns:
            Nothing.
        Raises:
            This method should not raise any Exception.
    """