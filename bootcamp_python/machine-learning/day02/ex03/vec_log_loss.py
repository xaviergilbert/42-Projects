import numpy as np 
import math

def sigmoid_(x):
    if type(x) == list or type(x) == np.ndarray:
        tab = []
        for elem in x:
            tab.append(1 / (1 + math.exp(-elem)))
        return tab
    return 1 / (1 + math.exp(-x))
 
def vec_log_loss_(y_true, y_pred, m, eps=1e-15):
    """
        Compute the logistic loss value.
        Args:
            y_true: a scalar or a numpy ndarray for the correct labels
            y_pred: a scalar or a numpy ndarray for the predicted labels
            m: the length of y_true (should also be the length of y_pred)
            eps: epsilon (default=1e-15)
        Returns:
            The logistic loss value as a float.
            None on any error.
        Raises:
            This function should not raise any Exception.
    """
    var = 1
    if (type(y_true) == np.ndarray):
        var = np.ones(len(y_true))
    tmp = (y_true * np.log(y_pred) + (var - y_true) * np.log(var - y_pred)) * (1 / m * -1)
    return np.sum(tmp)

def main():
    
    print("\ntest 1")
    x= 4
    y_true = 1
    theta = 0.5
    y_pred = sigmoid_(x * theta)
    m = 1 # length of y_true is 1 
    print(vec_log_loss_(y_true, y_pred, m)) 
    # 0.12692801104297152

    print("\ntest 2")
    x = np.array([1, 2, 3, 4])
    y_true = 0
    theta = np.array([-1.5, 2.3, 1.4, 0.7]) 
    y_pred = sigmoid_(np.dot(x, theta)) 
    m= 1
    print(vec_log_loss_(y_true, y_pred, m)) 
    # 10.100041078687479

    print("\ntest 3")
    x_new = np.arange(1, 13).reshape((3, 4))
    # print(x_new)
    y_true = np.array([1, 0, 1])
    theta = np.array([-1.5, 2.3, 1.4, 0.7])
    y_pred = sigmoid_(np.dot(x_new, theta))
    m = len(y_true)
    print(vec_log_loss_(y_true, y_pred, m))
    # 7.233346147374828

if __name__ == "__main__":
    main()