# import sklearn
# from sklearn.linear_model import LinearRegression
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
    tmp = 0.0
    if type(y_true) == int:
        y_true = [y_true]
        y_pred = [y_pred]
    for index in range(0, m):
        y_pred[index] += eps
        tmp +=  (y_true[index] * math.log(y_pred[index]) + (1 - y_true[index]) * math.log(1 - y_pred[index]))
    res = tmp / m * -1
    return float(res)

def main():
    print("\ntest 1 \n")
    x= 4
    y_true = 1
    theta = 0.5
    y_pred = sigmoid_(x * theta)
    print(y_pred)
    m = 1 # length of y_true is 1
    print("log_loss : \n", log_loss_(y_true, y_pred, m))


    print("\ntest 2 \n")
    x = [1, 2, 3, 4]
    y_true = 0
    theta = [-1.5, 2.3, 1.4, 0.7]
    x_dot_theta = sum([a*b for a, b in zip(x, theta)]) 
    y_pred = sigmoid_(x_dot_theta)
    m = 1
    print(log_loss_(y_true, y_pred, m))

    print("\ntest 3 \n")
    x_new = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
    y_true = [1, 0, 1]
    theta = [-1.5, 2.3, 1.4, 0.7]
    x_dot_theta = []
    for i in range(len(x_new)):
        my_sum = 0
        for j in range(len(x_new[i])):
            my_sum += x_new[i][j] * theta[j]
        x_dot_theta.append(my_sum)
    y_pred = sigmoid_(x_dot_theta)
    m = len(y_true)
    print(log_loss_(y_true, y_pred, m))

if __name__ == "__main__":
    main()