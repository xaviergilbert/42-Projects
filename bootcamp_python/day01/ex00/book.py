# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    book.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 10:14:00 by xgilbert          #+#    #+#              #
#    Updated: 2020/01/14 10:15:18 by xgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from recipe import Recipe
import datetime

class book:
    def __init__(self, name, var, recipes_list = {'lunch': []}):
        self.name = name
        self.last_update = datetime.datetime.now()
        self.created_date = datetime.datetime.now()
        self.recipes_list = recipes_list
        if type(var) == Recipe:
            self.add_recipe(var)
            print("On envoie a add recipe")

    def get_recipe_by_name(self, name):
        """Print a recipe with the name `name` and return the instance"""
        pass

    def get_recipes_by_types(self, recipe_type):
        """Get all recipe names for a given recipe_type """
        pass

    def add_recipe(self, recipe):
        """Add a recipe to the book and update last_update"""
        self.recipes_list[recipe.recipe_type].append(recipe)
        pass
        
    def __str__(self):
        """Return the string to print with the recipe info"""
        txt = ""
        """Your code goes here"""
        return txt