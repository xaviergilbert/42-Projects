import numpy as np
import matplotlib

def mat_vec_prod(w, x):
    tab = []
    f = lambda f, r : f * r
    for elem in w:
        tmp = 0
        for arg, arg1 in zip(elem, x):
            tmp += f(arg , arg1)
        tab.append(tmp)
    tab = np.array(tab)
    return tab

def gradient(x, y, theta):
    data = mat_vec_prod(x, theta)
    data = data - y
    print("result : ", data)
    tab = []
    for i in range(x.shape[1]):   
        tmp = 0.0
        for row, elem in zip(x, data):
            tmp += row[i] * elem
        tmp = tmp / x.shape[0]
        tab.append(tmp)
    tab = np.array(tab)
    print(tab)
    return (tab)

def predict_(theta, X):
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


def fit_(theta, X, Y, alpha, n_cycle):
    """
        Description:
            Performs a fit of Y(output) with respect to X.
        Args:
            theta: has to be a numpy.ndarray, a vector of dimension (number of features + 1, 1).
            X: has to be a numpy.ndarray, a matrix of dimension (number of training examples, number of features).
            Y: has to be a numpy.ndarray, a vector of dimension (number of training examples, 1).
        Returns:
            new_theta: numpy.ndarray, a vector of dimension (number of the features +1,1).
            None if there is a matching dimension problem.
        Raises: 
            This function should not raise any Exception.
    """
    n = float(len(X))
    n = X.shape[0] * X.shape[1]
    new_theta = theta
    for i in range(n_cycle): 
        Y_pred = predict_(new_theta, X)  # The current predicted value of Y
        D_m = (-2/n) * sum(X * (Y - Y_pred))  # Derivative wrt m
        D_c = (-2/n) * sum(Y - Y_pred)  # Derivative wrt c
        new_theta[0] = new_theta[0] - alpha * D_c
        new_theta[1:] = new_theta[1:] - alpha * np.reshape(D_m, (D_m.shape[0],1))
    return new_theta

def main():
    print("Premier exemple : ")
    X1 = np.array([[0.], [1.], [2.], [3.], [4.]])
    Y1 = np.array([[2.], [6.], [10.], [14.], [18.]])
    theta1 = np.array([[1.], [1.]])
    theta1 = fit_(theta1, X1, Y1, alpha = 0.01, n_cycle=2000)
    print("theta : ", theta1)
    print("nouvelle prediction : ", predict_(theta1, X1))

    print("Deuxieme exemple : ")
    X2 = np.array([[0.2, 2., 20.], [0.4, 4., 40.], [0.6, 6., 60.], [0.8, 8., 80.]])
    Y2 = np.array([[19.6], [-2.8], [-25.2], [-47.6]])
    theta2 = np.array([[42.], [1.], [1.], [1.]])
    theta2 = fit_(theta2, X2, Y2, alpha = 0.0005, n_cycle=42000)
    print("theta : ", theta2)
    print(predict_(theta2, X2))

if __name__ == "__main__":
    main()