/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:17:47 by akhercha          #+#    #+#             */
/*   Updated: 2019/02/17 15:17:49 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isnumber(char *str)
{
	int		i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if ((ft_isdigit((int)str[i]))
			|| ((i == 0) && ((str[i] == '-') || (str[i] == '+'))))
			i++;
		else
			return (0);
	}
	return (1);
}
