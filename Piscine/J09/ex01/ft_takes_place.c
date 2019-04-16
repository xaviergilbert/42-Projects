/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 17:44:28 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/08 16:19:07 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	matin(int hour)
{
	if (hour == 31)
		ft_putstr(" 1.00 A.M. AND 2.00 A.M.");
	if (hour == 32)
		ft_putstr(" 2.00 A.M. AND 3.00 A.M.");
	if (hour == 33)
		ft_putstr(" 3.00 A.M. AND 4.00 A.M.");
	if (hour == 34)
		ft_putstr(" 4.00 A.M. AND 5.00 A.M.");
	if (hour == 35)
		ft_putstr(" 5.00 A.M. AND 6.00 A.M.");
	if (hour == 36)
		ft_putstr(" 6.00 A.M. AND 7.00 A.M.");
	if (hour == 37)
		ft_putstr(" 7.00 A.M. AND 8.00 A.M.");
	if (hour == 38)
		ft_putstr(" 8.00 A.M. AND 9.00 A.M.");
	if (hour == 39)
		ft_putstr(" 9.00 A.M. AND 10.00 A.M.");
	if (hour == 10)
		ft_putstr(" 10.00 A.M. AND 11.00 A.M.");
	if (hour == 11)
		ft_putstr(" 11.00 A.M. AND 12.00 P.M.");
	if (hour == 12)
		ft_putstr(" 12.00 P.M. AND 01.00 P.M.");
}

void	apresmidi(int hour)
{
	if (hour == 13)
		ft_putstr(" 1.00 P.M. AND 2.00 P.M.");
	if (hour == 14)
		ft_putstr(" 2.00 P.M. AND 3.00 P.M.");
	if (hour == 15)
		ft_putstr(" 3.00 P.M. AND 4.00 P.M.");
	if (hour == 16)
		ft_putstr(" 4.00 P.M. AND 5.00 P.M.");
	if (hour == 17)
		ft_putstr(" 5.00 P.M. AND 6.00 P.M.");
	if (hour == 18)
		ft_putstr(" 6.00 P.M. AND 7.00 P.M.");
	if (hour == 19)
		ft_putstr(" 7.00 P.M. AND 8.00 P.M.");
	if (hour == 20)
		ft_putstr(" 8.00 P.M. AND 9.00 P.M.");
	if (hour == 21)
		ft_putstr(" 9.00 P.M. AND 10.00 P.M.");
	if (hour == 22)
		ft_putstr(" 10.00 P.M. AND 11.00 P.M.");
	if (hour == 23)
		ft_putstr(" 11.00 P.M. AND 12.00 A.M.");
	if (hour == 24)
		ft_putstr(" 12.00 A.M. AND 01.00 A.M.");
}

void	ft_takes_place(int hour)
{
	if (hour < 10)
		hour = hour + 30;
	ft_putstr("THE FOLLOWING TAKES PLACE BETWEEN");
	if (hour == 30)
		ft_putstr(" 12.00 A.M. AND 1.00 A.M.");
	matin(hour);
	apresmidi(hour);
	ft_putchar('\n');
}
