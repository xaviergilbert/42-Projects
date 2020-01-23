from FileLoader import FileLoader
import pandas as pd

def howManyMedalsByCountry(data, country):
    """
        Returns a dictionary of dictionaries giving the number and type of medal for each 
        competition where the country team earned medals.
    """
    data = data[data['Team'].eq(country)]
    data = data.sort_values(by=['Year'])
    previous_year = 0
    dictionary = {}
    for index, row in data.iterrows():
        year = (row["Year"])
        # print(year)
        # exit()
        if previous_year == year:
            continue
        gold = 0
        silver = 0
        bronze = 0
        new_data = data[data['Year'].eq(year)]
        gold = new_data[new_data['Medal'].eq("Gold")]
        new_gold = gold.drop_duplicates(subset = "Event").shape[0]  
        silver = new_data[new_data['Medal'].eq("Silver")]
        new_silver = silver.drop_duplicates(subset = "Event").shape[0]  
        silver = new_data[new_data['Medal'].eq("Bronze")]
        new_bronze = silver.drop_duplicates(subset = "Event").shape[0]  
        previous_year = year
        dictionary[year] = {
                'G': new_gold,
                'S': new_silver,
                'B': new_bronze
        }
    print(dictionary)

if __name__ == "__main__":
    loader = FileLoader()
    data = loader.load("athlete_events.csv")
    # howManyMedalsByCountry(data, 'Martian Federation')
    howManyMedalsByCountry(data, 'France')