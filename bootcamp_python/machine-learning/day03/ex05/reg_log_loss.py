import numpy as np 

def sigmoid_(x):
    x = np.array(x)
    return 1 / (1 + np.exp(-x))

def reg_log_loss_(y_true, y_pred, m, theta, lambda_, eps= 1e-15):
    """
        Compute the logistic loss value.
        Args:
            y_true: a scalar or a numpy ndarray for the correct labels
            y_pred: a scalar or a numpy ndarray for the predicted labels
            m: the length of y_true (should also be the length of y_pred)
            lambda_: a float for the regularization parameter
            eps: epsilon (default=1e-15)
        Returns:
            The logistic loss value as a float.
            None on any error.
        Raises:
            This function should not raise any Exception.
    """
    loss = 1 / m * np.sum((-y_true * np.log(y_pred+eps) - (1 - y_true) * np.log((1 - y_pred)+eps)) + lambda_ * theta[1:]**2)
    return loss

def main():
    # Test n.1
    x_new = np.arange(1, 13).reshape((3, 4))
    y_true = np.array([1, 0, 1])
    theta = np.array([-1.5, 2.3, 1.4, 0.7])
    y_pred = sigmoid_(np.dot(x_new, theta))
    m = len(y_true)
    print(reg_log_loss_(y_true, y_pred, m, theta, 0.0))
    # 7.233346147374828

    # Test n.2
    x_new = np.arange(1, 13).reshape((3, 4))
    y_true = np.array([1, 0, 1])
    theta = np.array([-1.5, 2.3, 1.4, 0.7])
    y_pred = sigmoid_(np.dot(x_new, theta))
    m = len(y_true)
    print(reg_log_loss_(y_true, y_pred, m, theta, 0.5))
    # 8.898346147374827

    # Test n.3
    print(reg_log_loss_(y_true, y_pred, m, theta, 1))
    # 10.563346147374826

    # Test n.4
    x_new = np.arange(1, 13).reshape((3, 4))
    y_true = np.array([1, 0, 1])
    theta = np.array([-5.2, 2.3, -1.4, 8.9])
    y_pred = sigmoid_(np.dot(x_new, theta))
    m = len(y_true)
    print(reg_log_loss_(y_true, y_pred, m, theta, 1))
    # 49.346258798303566

    # Test n.5
    print(reg_log_loss_(y_true, y_pred, m, theta, 0.3))
    # 22.86292546497024

    # Test n.6
    print(reg_log_loss_(y_true, y_pred, m, theta, 0.9))
    # 45.56292546497025    

if __name__ == "__main__":
    main()