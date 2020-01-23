from FileLoader import FileLoader

def howManyMedals(data, name):
    """
        Returns a dictionary of dictionaries giving the number and type of medalsfor each year 
        during which the participant won medals.
    """
    data = data[data['Name'].eq(name)]
    print(data)
    previous_year = 0
    dictionary = {}
    for index, row in data.iterrows():
        year = (row["Year"])
        if previous_year == year:
            continue
        gold = 0
        silver = 0
        bronze = 0
        new_data = data[data['Year'].eq(year)]
        gold = new_data[new_data['Medal'].eq("Gold")].shape[0]
        silver = new_data[new_data['Medal'].eq("Silver")].shape[0]
        bronze = new_data[new_data['Medal'].eq("Bronze")].shape[0]
        previous_year = year
        dictionary[year] = {
                'G': gold,
                'S': silver,
                'B': bronze
        }
    print(dictionary)
    return dictionary

if __name__ == "__main__":
    loader = FileLoader()
    data = loader.load("athlete_events.csv")
    howManyMedals(data, 'Kjetil Andr Aamodt')