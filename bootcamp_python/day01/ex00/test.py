# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 10:15:43 by xgilbert          #+#    #+#              #
#    Updated: 2020/01/14 10:15:50 by xgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from book import Book
from recipe import Recipe

def main():
    tarte = Recipe("tartiflette", 2, 15, ["fromage", "lait", "oeufs"], "dej")
    print(str(tarte))
    print(Recipe.)
    # book = Book("nom", {"starter": [], "lunch": []})
    # book.get_recipe_by_name("tartiflette")
    # print(book.creation_date)

if __name__ == "__main__":
    main()