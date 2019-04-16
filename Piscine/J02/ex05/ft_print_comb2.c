/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 10:11:27 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/20 19:31:55 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_putchar(char c);

char	ft_print_char(char a, char b, char c, char d)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(' ');
	ft_putchar(c);
	ft_putchar(d);
	if (a != '9' || b != '8')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	d++;
	return (d);
}

int		ft_print_comb2(char a, char b, char c, char d)
{
	a = '0';
	b = '0';
	while (a <= '9')
	{
		while (b <= '9')
		{
			d = b + 1;
			c = a;
			while (c <= '9')
			{
				while (d <= '9')
				{
					d = ft_print_char(a, b, c, d);
				}
				c++;
				d = '0';
			}
			b++;
		}
		b = '0';
		a++;
	}
	return (0);
}
