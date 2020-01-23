# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    filterwords.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 18:14:01 by xgilbert          #+#    #+#              #
#    Updated: 2020/01/13 19:22:46 by xgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import string

def main(chaine, length):
    index = 0
    tab = []
    while index < len(chaine) and chaine[index]:
        while chaine[index] in string.whitespace:
            index += 1
        wordLength = 0
        while index + wordLength < len(chaine) and chaine[index + wordLength] not in string.whitespace:
            wordLength += 1
        if wordLength > length:
            tab.append(chaine[index:index + wordLength])
        index += wordLength
    print(tab)

if __name__ == "__main__":
    chaine = sys.argv[1]
    length = int(sys.argv[2])
    main(chaine, length)
