import numpy as np
import pandas as pd
from FileLoader import FileLoader

class MyPlotLib:

    def histogram(self, data, features):
        data.plot.hist(self, by=features, bins=len(features))

    def density(self, data, features):
        pass

    def pair_plot(data, features):
        pass

    def box_plot(data, features):
        pass

if __name__ == "__main__":
    loader = FileLoader()
    data = loader.load("athlete_events.csv")
    graph = MyPlotLib()
    graph.histogram(data, ['Height', 'Weight'])