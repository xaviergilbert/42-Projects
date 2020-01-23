import pandas as pd 

class FileLoader:

    def load(self, path):
        """
        The argument of this method is the file path of the dataset to load. 
        It must display a message specifying the dimensions of the dataset (e.g. 340 x 500). 
        The method returns the dataset loaded as a pandas.DataFrame.
        """
        data = pd.read_csv(path) 
        print("Loading dataset of dimensions ", data.shape[0], "x", data.shape[1])
        return data

    def display(self, df, n):
        """
        Takes a pandas.DataFrame and an integer as arguments. 
        This method displays the first n rows of the dataset if n is positive, or the last n rows if n is negative.
        """
        print(df[:n]) if n >= 0 else print(df[n:])


if __name__ == "__main__":
    loader = FileLoader()
    data = loader.load("athlete_events.csv")
    loader.display(data, 12)
