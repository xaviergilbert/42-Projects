/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 20:09:15 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/03 15:58:30 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_putchar(char c);

int		ft_print_comb(char a, char b, char c)
{
	a = '0';
	while (a < 56)
	{
		b = a + 1;
		while (b < 57)
		{
			c = b + 1;
			while (c < 58)
			{
				ft_putchar(a);
				ft_putchar(b);
				ft_putchar(c);
				if (a == 55 && b == 56 && c == 57)
					return (0);
				ft_putchar(',');
				ft_putchar(' ');
				c++;
			}
			b++;
		}
		a++;
	}
	return (0);
}
