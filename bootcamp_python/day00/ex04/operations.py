# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    operations.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 14:12:11 by xgilbert          #+#    #+#              #
#    Updated: 2020/01/13 14:33:45 by xgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import string
import sys

def main(num1, num2):
    somme = num1 + num2
    diff = num1 - num2
    product = num1 * num2
    if num2 == 0:
        quotient = "ERROR (div by zero)"
        remainder = "ERROR (modulo by zero)"
    else:
        quotient = num1 / num2
        remainder = num1 % num2
    print("Sum : " + str(somme))
    print("Difference : " + str(diff))
    print("Product : " + str(product))
    print("Quotient : " + str(quotient))
    print("Remainder : " + str(remainder))

if __name__ == "__main__":
    if len(sys.argv) == 3:
        if (str.isnumeric(sys.argv[1]) and str.isnumeric(sys.argv[2])):
            num1 = int(sys.argv[1])
            num2 = int(sys.argv[2])
            main(num1, num2)
        else:
            print("InputError: only numbers")
    else:
        print("InputError: must receive two numbers")
