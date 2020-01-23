# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    recipe.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 16:15:47 by xgilbert          #+#    #+#              #
#    Updated: 2020/01/13 18:13:08 by xgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def print_recipe(cookbook):
    print("Please enter the recipe's name to get its details:")
    recipe_name = input()
    correct_name = 0
    for recipe in cookbook:
        if recipe == recipe_name:
            correct_name = 1
            break
    if correct_name == 0:
        print("Wrong recipe name")
        print_recipe()
    print(recipe, ":", cookbook[recipe])

def print_all_recipes(cookbook):
    for recipe in cookbook:
       print(recipe, ":", cookbook[recipe])

def delete_recipe(cookbook):
    correct_name = 0
    del_recipe = input("Which recipe would you want to delete ?")
    for recipe in cookbook:
        if recipe == del_recipe:
            correct_name = 1
            break
    if correct_name == 0:
        print("Wrong recipe name")
        delete_recipe()
    del cookbook[delete_recipe]

def new_recipe(cookbook):
    recipe_name = input("What is the name of your new recipe ?\n")
    str_ingredients = input("What are your ingredients ? (ex: ingredients, ingredients, etc...)\n")
    ingredients = str_ingredients.split(", ")
    meal = input("Which type of meal is it ?\n")
    prep_time = input("How long to prepare it ? (in minutes)\n")
    cookbook[recipe_name] = {'ingredients': ingredients, 'meal': meal, 'prep_time': prep_time}

def main(cookbook):
    while 1:
        print("Please select an option by typing the corresponding number:")
        print("1: Add a recipe")
        print("2: Delete a recipe")
        print("3: Print a recipe")
        print("4: Print the cookbook")
        print("5: Quit")
        value = input()
        if value == '1':
            new_recipe(cookbook)
        if value == '2':
            delete_recipe(cookbook)
        if value == '3':
            print_recipe(cookbook)
        if value == '4':
            print_all_recipes(cookbook)
        if value == '5':
            break

if __name__ == "__main__":
    cookbook = {
    'sandwich': {'ingredients': ["ham", "bread", "cheese", "tomatoes"], 'meal': "lunch", 'prep_time': 10},
    'cake': {'ingredients': ["flour", "sugar", "eggs"], 'meal': "dessert", 'prep_time': 60},
    'salad': {'ingredients': ["avocado", "aragula", "tomatoes", "spinach"], 'meal': "lunch", 'prep_time': 15},
    }
    main(cookbook)
