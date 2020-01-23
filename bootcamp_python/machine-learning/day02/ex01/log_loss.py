# import sklearn
from sklearn.linear_model import LinearRegression
import math

def sigmoid_(x):
    if type(x) == list:
        tab = []
        for elem in x:
            tab.append(1 / (1 + math.exp(-elem)))
        return tab
    return 1 / (1 + math.exp(-x))

def log_loss_(y_true, y_pred, m, eps=1e-15):
    """
        Compute the logistic loss value.
        Args:
            y_true: a scalar or a list for the correct labels
            y_pred: a scalar or a list for the predicted labels
            m: the length of y_true (should also be the length of y_pred)
            eps: epsilon (default=1e-15)
        Returns:
            The logistic loss value as a float.
            None on any error.
        Raises:
            This function should not raise any Exception.
    """
    my_lr = LogisticRegression()
    return my_lr.loss(y_true, y_pred)

def main():
    x= 4
    y_true = 1
    theta = 0.5
    y_pred = sigmoid_(x * theta)
    print(y_pred)
    m = 1 # length of y_true is 1
    print("log_loss : \n", log_loss_(y_true, y_pred, m))

if __name__ == "__main__":
    main()