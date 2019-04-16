/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_positive_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 16:07:04 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/01 14:54:36 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		isvldstr(char *str)
{
	int			i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	return (i <= 11);
}

int				ft_is_positive_int(char *nb)
{
	if (!nb)
		return (0);
	if (isvldstr(nb))
		if (ft_atol(nb) >= 0 && ft_atol(nb) <= INT_MAX)
			return (1);
	return (0);
}
