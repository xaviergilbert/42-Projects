import numpy as np 

def reg_linear_grad(x, y, theta, lambda_):
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
    gradient = np.array(np.mat(x.dot(theta) - y) * np.mat(x) / len(y))
    reg_gradient = gradient + (lambda_ * np.sum(theta**2, axis=0) / len(y))
    # reg_gradient = gradient * (1 - alpha * lambda_ / len(y)) - (alpha / len(y) * gradient)
    # ( + np.sum(theta**2, axis=0) * lambda_)
    return reg_gradient 

def main():
    X = np.array([
         [ -6, -7, -9],
        [ 13, -2, 14],
        [ -7, 14, -1],
        [ -8, -4, 6],
        [ -5, -9, 6],
        [ 1, -5, 11],
        [ 9, -11, 8]])
    Y = np.array([2, 14, -13, 5, 12, 4, -19])
    Z = np.array([3,10.5,-6])
    print(reg_linear_grad(X, Y, Z, 1))
    #array([-192.64285714, 887.5,        -679.57142857])
    print(reg_linear_grad(X, Y, Z, 0.5))
    #array([-192.85714286, 886.75,     -679.14285714])
    print(reg_linear_grad(X, Y, Z, 0.0))
    #array([-193.07142857, 886.,         -678.71428571])

if __name__ == "__main__":
    main()