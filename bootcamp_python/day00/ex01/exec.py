# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    exec.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 10:25:36 by xgilbert          #+#    #+#              #
#    Updated: 2020/01/13 12:32:50 by xgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def main():
    str = ""
    iter = 0
    for arg in sys.argv[1:]:
        arg = arg[::-1]
        arg = arg.swapcase()
        if arg.endswith(" ") or iter == 0:
            str = arg + str
        else:
            str = arg + " " + str
        iter = iter + 1
    print(str)

if __name__ == "__main__":
    main()

