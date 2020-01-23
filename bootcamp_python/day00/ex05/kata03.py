# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    kata03.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 16:03:13 by xgilbert          #+#    #+#              #
#    Updated: 2020/01/13 16:13:10 by xgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

if __name__ == "__main__":
    phrase = "The right format"
    phraselen = len(phrase)
    totallen = 42 - phraselen
    startPhrase = (totallen - 1) * '-'
    print(startPhrase + phrase)
