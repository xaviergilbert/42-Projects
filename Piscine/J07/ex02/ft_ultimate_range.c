/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 11:41:24 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/19 10:27:08 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		len;
	int		*tab;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	len = max - min;
	tab = (int*)malloc(sizeof(*tab) * (len));
	i = 0;
	while (min < max)
		tab[i++] = min++;
	*range = tab;
	return (len);
}
