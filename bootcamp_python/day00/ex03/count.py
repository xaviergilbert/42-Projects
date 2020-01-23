# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    count.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 12:09:05 by xgilbert          #+#    #+#              #
#    Updated: 2020/01/13 14:09:15 by xgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import string
import sys

def text_analyzer(text = None):
    print("hello")
    index = 0
    countUpperCase = 0
    countLowerCase = 0
    countPunctuation = 0
    countSpace = 0
    if text == None:
        print("Insert a text :")
        text = input()
    while index < len(text):
        if text[index].isupper():
            countUpperCase = countUpperCase + 1
        elif text[index].islower():
            countLowerCase = countLowerCase + 1
        elif text[index] in string.punctuation:
            countPunctuation = countPunctuation + 1
        elif text[index].isspace():
            countSpace = countSpace + 1
        index = index + 1
    print("The text contains " + str(index + 1) + " characters : \n\tNumber of uppercase char : " + str(countUpperCase) + "\n\tNumber or lowercase chars : " + str(countLowerCase) + "\n\tNumber of punctuation chars : " + str(countPunctuation) + "\n\tNumber of space chars : " + str(countSpace))
