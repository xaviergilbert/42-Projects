/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:30:09 by xgilbert          #+#    #+#             */
/*   Updated: 2018/06/28 14:21:18 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		taille_malloc(intmax_t nb, intmax_t base)
{
	int			i;

	i = 1;
	while (nb >= base)
	{
		i++;
		nb /= base;
	}
	return (i);
}

char			*ft_itoa_base(intmax_t nb, intmax_t base)
{
	char		*str;
	int			p;

	p = taille_malloc(nb, base);
	if (base < 2 || 16 < base || (base != 10 && nb < 0)
	|| !(str = (char *)malloc(sizeof(char) * p + 2)))
		return (NULL);
	p = 0;
	while (base <= nb)
	{
		if (base > 10 && (nb % base >= 10))
			str[p++] = (nb % base) - 10 + 'a';
		else
			str[p++] = (nb % base) + '0';
		nb /= base;
	}
	if (base > 10 && (nb % base >= 10))
		str[p++] = (nb % base) - 10 + 'a';
	else
		str[p++] = (nb % base) + '0';
	if (base == 10 && nb < 0)
		str[p++] = '-';
	str[p] = '\0';
	return (ft_strrev(str));
}
