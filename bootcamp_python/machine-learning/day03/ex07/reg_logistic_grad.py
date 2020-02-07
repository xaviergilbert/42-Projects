import numpy as np 

def sigmoid_(x):
    x = np.array(x)
    return 1 / (1 + np.exp(-x))

def reg_logistic_grad(y, x, theta, lambda_):
    """
        Computes the regularized linear gradient of three non-empty
            numpy.ndarray, with two for-loop. The three arrays must have compatible
            dimensions.
        Args:
            y: has to be a numpy.ndarray, a vector of dimension m * 1.
            x: has to be a numpy.ndarray, a matrix of dimesion m * n.
            theta: has to be a numpy.ndarray, a vector of dimension n * 1.
            alpha: has to be a float.
            lambda_: has to be a float.
        Returns:
            A numpy.ndarray, a vector of dimension n * 1, containing the results of
                the formula for all j.
            None if y, x, or theta are empty numpy.ndarray.
            None if y, x or theta does not share compatibles dimensions.
        Raises:
            This function should not raise any Exception.
    """
    y_pred = sigmoid_(np.dot(x, theta))
    # print(y_pred)
    # gradient_0 = 1 / len(y) * (np.sum(y_pred - y) * x[0])
    gradient = (np.sum(y_pred - y) * np.sum(x, axis = 0) / len(y) + lambda_ / len(y) * theta)
    # gradient = np.append(gradient_0, gradient_n)
    return gradient

def main():
    X = np.array([
            [ -6, -7, -9],
            [ 13, -2, 14],
            [ -7, 14, -1],
            [ -8, -4, 6],
            [ -5, -9, 6],
            [ 1, -5, 11],
            [ 9, -11, 8]])
    Y = np.array([1,0,1,1,1,0,0])
    Z = np.array([1.2,0.5,-0.32])
    print(reg_logistic_grad(Y, X, Z, 1))
    #array([ 6.69780169, -0.33235792, 2.71787754])
    print(reg_logistic_grad(Y, X, Z, 0.5))
    #array([ 6.61208741, -0.3680722, 2.74073468])
    print(reg_logistic_grad(Y, X, Z, 0.0))
    #array([ 6.52637312, -0.40378649, 2.76359183])

if __name__ == "__main__":
    main()