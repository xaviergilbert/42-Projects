class Recipe:
    def __init__(self, name, cooking_lvl, cooking_time, ingredients, recipe_type, description = ""):
        self.set_name(name)
        self.set_cooking_time(cooking_time)
        self.set_cooking_lvl(cooking_lvl)
        self.set_ingredients(ingredients)
        self.set_description(description)
        self.set_recipe_type(recipe_type)

    def set_name(self, name):
        if not isinstance(name, str):
            raise TypeError("name must be set to a string")
        self.name = name

    def set_cooking_time(self, cooking_time):
        if not isinstance(cooking_time, int):
            raise TypeError("cooking_time must be set to an int")
        self.cooking_time = cooking_time

    def set_cooking_lvl(self, cooking_lvl):
        if not isinstance(cooking_lvl, int):
            raise TypeError("cooking_lvl must be set to an int")
        self.cooking_lvl = cooking_lvl

    def set_ingredients(self, ingredients):
        if not isinstance(ingredients, list):
            raise TypeError("ingredients must be set to a list")
        self.ingredients = ingredients

    def set_description(self, description):
        if not isinstance(description, str):
            raise TypeError("description must be set to a str")
        self.description = description

    def set_recipe_type(self, recipe_type):
        if not isinstance(recipe_type, str):
            raise TypeError("recipe_type must be set to a str")
        self.recipe_type = recipe_type

    def __str__(self):
        ingredients = ", ".join(self.ingredients)
        return ("name : " + self.name + "\ncooking_time : " + str(self.cooking_time) + "\ncooking_lvl : "
                + str(self.cooking_lvl) + "\ningredients : " + ingredients + "\ndescription : " 
                + self.description + "\nrecipe_type : " + self.recipe_type)