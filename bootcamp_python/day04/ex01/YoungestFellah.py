from FileLoader import FileLoader

def youngestFellah(data, year):
    """
    return a dictionary containing the age of the youngest woman and man who took part
    int the Olympics on that year. The name of the dictionary's keys is up to you, but
    it must be self-explanatory.
    """
    # pd.data.filter()
    data_year = data[data['Year'].eq(year)]
    data_f = data_year[data_year['Sex'].eq('F')]
    data_m = data_year[data_year['Sex'].eq('M')]
    dictionary = {
        'F': data_f.Age.min(),
        'M': data_m.Age.min()
    }
    print(dictionary)


if __name__ == "__main__":
    loader = FileLoader()
    data = loader.load("athlete_events.csv")
    # loader.display(data, 12)
    youngestFellah(data, 2004)