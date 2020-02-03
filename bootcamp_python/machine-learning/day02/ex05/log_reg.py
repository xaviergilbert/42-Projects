import numpy as np 
import pandas as pd
import math
import sklearn as sk
 
class LogisticRegressionBatchGd:
    def __init__(self, alpha=0.001, max_iter=1000, verbose=False, learning_rate='constant'):
        self.alpha = alpha
        self.max_iter = max_iter
        self.verbose = verbose
        self.learning_rate = learning_rate # can be 'constant' or 'invscaling'
        self.thetas = []
        # Your code here (e.g. a list of loss for each epochs...)

    def sigmoid_(self, x):
        x = np.array(x)
        return 1 / (1 + np.exp(-x))

    def vec_log_loss_(self, y_true, y_pred, m, eps=1e-15):
        loss = (np.dot(y_true, np.log(np.add(y_pred,eps))) + np.dot((1 - y_true), np.log(1-y_pred+eps))) * (-1/m)
        return loss

    def vec_log_gradient_(self, x, y_true, y_pred):
        return np.sum(y_pred - y_true) * np.mean(x, axis = 0) if x.ndim == 2 else np.sum(y_pred - y_true) * x
        
    def fit(self, x_train, y_train):
        """
            Fit the model according to the given training data.
            Args:
                x_train: a 1d or 2d numpy ndarray for the samples
                y_train: a scalar or a numpy ndarray for the correct labels
            Returns:
                self : object
                None on any error.
            Raises:
                This method should not raise any Exception.
        """
        n = x_train.shape[0] * x_train.shape[1]
        self.thetas = np.zeros(x_train.shape[1] + 1)
        print(self.thetas.shape, x_train.shape)
        for i in range(self.max_iter): 
            # Y_pred = np.array(self.sigmoid_(np.dot(x_train, self.thetas[1:])))
            Y_pred = self.predict(x_train)
            if i % 150 == 0:
                print("tour : ", i)
                print("loss : ", self.vec_log_loss_(y_train, Y_pred, len(y_train)))
                print("score : ", self.score(x_train, y_train))
            D_m = (-2/n) * sum(np.sum(x_train, axis = 1) * (y_train - Y_pred))  # Derivative wrt m
            D_c = (-2/n) * sum(y_train - Y_pred)  # Derivative wrt c
            self.thetas[0] = self.thetas[0] - self.alpha * D_c
            self.thetas[1:] = self.thetas[1:] - self.alpha * D_m


    def predict(self, x_train):
        """
            Predict class labels for samples in x_train.
            Arg:
                x_train: a 1d or 2d numpy ndarray for the samples
            Returns:
                y_pred, the predicted class label per sample.
                None on any error.
            Raises:
                This method should not raise any Exception.
        """
        tmp = np.dot(x_train, self.thetas[1:]) + self.thetas[:1]
        y_pred = np.array(self.sigmoid_(tmp))
        y_pred = np.around(y_pred)
        return y_pred

    def score(self, x_train, y_train):
        """
            Returns the mean accuracy on the given test data and labels.
            Arg:
                x_train: a 1d or 2d numpy ndarray for the samples
                y_train: a scalar or a numpy ndarray for the correct labels
            Returns:
                Mean accuracy of self.predict(x_train) with respect to y_true
                None on any error.
            Raises:
                This method should not raise any Exception.
        """
        y_pred = self.predict(x_train)
        score = (np.around(y_pred) == y_train) + 0
        score = np.mean(score)
        return score



def main():
    # We load and prepare our train and test dataset into x_train, y_train and x_test, y_test
    df_train = pd.read_csv('train_dataset_clean.csv', delimiter=',', header=None, index_col=False)
    x_train, y_train = np.array(df_train.iloc[:, 1:82]), df_train.iloc[:, 0]

    df_test = pd.read_csv('test_dataset_clean.csv', delimiter=',', header=None, index_col=False)
    x_test, y_test = np.array(df_test.iloc[:, 1:82]), df_test.iloc[:, 0]

    # We set our model with our hyperparameters : alpha, max_iter, verbose and learning_rate
    model = LogisticRegressionBatchGd(alpha=0.01, max_iter=1500, verbose=True, learning_rate='constant')
    
    # We fit our model to our dataset and display the score for the train and test datasets
    model.fit(x_train, y_train)
    # print("theta : ", model.thetas)
    print(f'Score on train dataset : {model.score(x_train, y_train)}')
    y_pred = model.predict(x_test)
    print(f'Score on test dataset : {(y_pred == y_test).mean()}')

if __name__ == "__main__":
    main()