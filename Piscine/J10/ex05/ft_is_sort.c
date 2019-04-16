/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:03:56 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/20 18:59:04 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		a;
	int		d;

	i = 0;
	a = 1;
	while (i < length)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			a = 0;
		i++;
	}
	i = 0;
	d = 1;
	while (i < length)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			d = 0;
		i++;
	}
	if (a == 1)
		return (1);
	if (d == 1)
		return (1);
	return (0);
}
