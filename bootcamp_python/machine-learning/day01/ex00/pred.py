import numpy as np

def predict_(theta, X):
    """
        Description:
            Prediction of output using the hypothesis function (linear model).
        Args:
            theta: has to be a numpy.ndarray, a vector of dimension (number of features + 1 , 1).
            X: has to be a numpy.ndarray, a matrix of dimension (number of training exemples, number of features).
        Returns:
            pred: numpy.ndarray, a vector of dimension (number of the training exemples, 1).
            None if X does not match the dimension of theta.
        Raises:
            This function should not raise any Exception.
    """
    tab = []
    for j in range(X.shape[0]):
        i = 0
        tmp = 0
        while i < X.shape[1] + 1:
            if i == 0:
                tmp = 1 * theta[i]
            else:
                tmp += X[j][i - 1] * theta[i]
            i += 1
        tab.append(tmp)
    tab = np.array(tab)
    return tab

def main():
    X1 = np.array([[0.], [1.], [2.], [3.], [4.]])
    theta1 = np.array([[2.], [4.]])
    print(predict_(theta1, X1))
    #resultat espere:
    #array([[2], [6], [10], [14.], [18.]])

    X3 = np.array([[0.2, 2., 20.], [0.4, 4., 40.], [0.6, 6., 60.], [0.8, 8., 80.]])
    theta3 = np.array([[0.05], [1.], [1.], [1.]])
    print(predict_(theta3, X3))

if __name__== "__main__":
    main()