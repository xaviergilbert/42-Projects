from FileLoader import FileLoader

def proportionBySport(data, year, sport, gender):
    """
        The function returns a float corresponding to the proportion (percentage) of participant who
        played the given sport among the participant of the given gender.
        The function answers questions like the following : "What was the percentage of female basketball players among all the
        female participants of the 2016 Olympics ?"
    """
    data = data[data['Year'].eq(year)]
    data = data[data['Sex'].eq(gender)]
    new_data = data.drop_duplicates(subset = "Name", keep = False)
    gender_particpant_global = new_data.shape[0]
    print(gender_particpant_global)

    data_sport = data[data['Sport'].eq(sport)]
    new_data = data_sport.drop_duplicates(subset = "Name", keep = False)
    gender_sport_participant = new_data.shape[0]
    print(gender_sport_participant)
    res = gender_sport_participant / gender_particpant_global
    print(res)

if __name__ == "__main__":
    loader = FileLoader()
    data = loader.load("athlete_events.csv")
    proportionBySport(data, 2004, 'Tennis', 'F')