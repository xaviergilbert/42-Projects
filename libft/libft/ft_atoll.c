/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:04:31 by akhercha          #+#    #+#             */
/*   Updated: 2019/02/17 16:09:56 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atoll(const char *str)
{
	unsigned long long	nbr;
	int					neg;

	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		neg = 1;
		str++;
	}
	else
	{
		neg = 0;
		if (*str == '+')
			str++;
	}
	nbr = 0;
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (neg) ? -(long long)nbr : (long long)nbr;
}
