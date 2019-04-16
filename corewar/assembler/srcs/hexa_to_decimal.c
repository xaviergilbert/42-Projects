/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_to_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:40:34 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/13 12:45:30 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			ft_pow_base(int nb, int base)
{
	int				ret;

	ret = 1;
	if (base > 2)
		nb++;
	while (nb > 1)
	{
		ret = ret * 16;
		nb--;
	}
	return (ret);
}

int			ft_tall_hexa(char c)
{
	static char		*hexa = "0123456789ABCDEF";
	int				i;

	i = 0;
	while (hexa[i] && hexa[i] != c)
		i++;
	return (i);
}

int			base_to_decimal(char *str, int base)
{
	int				res;
	int				i;
	int				j;

	i = 0;
	res = 0;
	str = ft_putmaj(str);
	j = (ft_strlen(str) - 1);
	while (str[i])
	{
		if (j >= 1)
			res = res + ft_tall_hexa(str[i]) * (ft_pow_base(j, base));
		else
			res = res + ft_tall_hexa(str[i]);
		i++;
		j--;
	}
	return (res);
}
