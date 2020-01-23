# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    kata01.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 14:49:11 by xgilbert          #+#    #+#              #
#    Updated: 2020/01/13 15:08:54 by xgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

if __name__ == "__main__":
    languages = {
    'Python': 'Guido van Rossum',
    'Ruby': 'Yukihiro Matsumoto',
    'PHP': 'Rasmus Lerdorf',
    }
    for language in languages:
        print(language + " was created by " + languages[language])
