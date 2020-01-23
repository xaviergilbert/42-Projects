# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    whois.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 11:36:59 by xgilbert          #+#    #+#              #
#    Updated: 2020/01/13 12:36:42 by xgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def main():
    iter = 0
    answer = "NO ARGUMENT"
    for arg in sys.argv[1:]:
        i = 0
        if iter == 0:
            try:
                arg = int(arg)
                if arg % 2 == 0 and arg != 0:
                    answer = "I'm Even."
                elif arg != 0:
                    answer = "I'm Odd."
                else:
                    answer = "I'm Zero."
            except ValueError:
                answer = "ERROR"
                pass
        else:
            answer = "ERROR"
        iter = iter + 1
    print(answer)

if __name__ == "__main__":
    main()
