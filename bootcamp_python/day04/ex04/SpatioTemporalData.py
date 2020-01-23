from FileLoader import FileLoader

class SpatioTemporalData:
    def __init__(self, data):
        self.data = data

    def when(self, location):
        """
            This method takes a location as an argument and returns a list containing the 
            years where games were held in the given location.
        """
        data_city = self.data[self.data['City'].eq(location)]
        new_data = data_city.drop_duplicates(subset = "Year")
        years = []
        for index, row in new_data.iterrows():
            years.append(row["Year"])
        print(years)

    def where(self, date):
        """
            This methods takes a date as an argument and returns the location where the
            Olympics took place in the given year.
        """
        data_date = self.data[self.data['Year'].eq(date)]
        new_data = data_date.drop_duplicates(subset = "Year")
        location = []
        for index, row in new_data.iterrows():
            location.append(row["City"])
        print(location)

if __name__ == "__main__":
    loader = FileLoader()
    data = loader.load("athlete_events.csv")
    sp = SpatioTemporalData(data)
    sp.where(1896)
    sp.where(2016)
    # sp.when('Athina')
    # sp.when('Paris')