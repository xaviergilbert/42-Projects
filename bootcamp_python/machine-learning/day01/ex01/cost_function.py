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

def cost_elem_(theta, X, Y):
    """
        Description:
            Calculates all the elements (0.5/M) * (y_pred - y)^2 of the cost function.
        Args:
            theta: has to be a numpy.ndarray, a vector of dimension (number of features + 1, 1).
            X: has to be a numpy.ndarray, a matrix of dimension (number of training examples, number of features).
        Returns:
            J_elem: numpy.ndarray, a vector of dimension (number of the training examples,1).
            None if there is a dimension matching problem between X, Y or theta.
        Raises:
            This function should not raise any Exception.
    """
    J_elem = predict_(theta, X)
    J_elem = ((J_elem - Y) ** 2) / (2 * X.shape[0])
    return J_elem

def cost_(theta, X, Y):
    """
        Description:
            Calculates the value of cost function.
        Args:
            theta: has to be a numpy.ndarray, a vector of dimension (number of features + 1, 1).
            X: has to be a numpy.ndarray, a vector of dimension (number of training examples, number of features).
        Returns:
            J_value : has to be a float.
            None if X does not match the dimension of theta.
        Raises:
            This function should not raise any Exception.
    """
    J_value = sum(cost_elem_(theta, X, Y))
    return J_value

def main():
    print("Premier exemple : ")
    X1 = np.array([[0.], [1.], [2.], [3.], [4.]])
    theta1 = np.array([[2.], [4.]])
    Y1 = np.array([[2.], [7.], [12.], [17.], [22.]])
    print("Premiere fonction: \n", cost_elem_(theta1, X1, Y1))
    print("Deuxieme fonction: ", cost_(theta1, X1, Y1))

    print("\nDeuxieme exemple : ")
    X2 = np.array([[0.2, 2., 20.], [0.4, 4., 40.], [0.6, 6., 60.], [0.8, 8., 80.]])
    theta2 = np.array([[0.05], [1.], [1.], [1.]])
    Y2 = np.array([[19.], [42.], [67.], [93.]])
    print("Premiere fonction: \n", cost_elem_(theta2, X2, Y2))
    print("Deuxieme fonction: ", cost_(theta2, X2, Y2))

if __name__ == "__main__":
    main()