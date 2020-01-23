# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    kata02.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 15:09:11 by xgilbert          #+#    #+#              #
#    Updated: 2020/01/13 15:59:28 by xgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

if __name__ == "__main__":
    t = (3,30,2019,9,25)
 #   (hour, minutes, year, month, day)
    month = str(t[3])
    day = str(t[4])
    hour = str(t[0])
    minutes = str(t[1])
    if t[3] < 10:
        month = "0" + month
    if t[4] < 10:
        day = "0" + day
    if t[0] < 10:
        hour = "0" + hour
    if t[1] < 10:
        minutes = "0" + minutes
    year = str(t[2])
    print(month + "/" + day + '/' + year + ' ' + hour + ":" + minutes)
