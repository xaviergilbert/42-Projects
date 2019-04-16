/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_ends_with.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 14:53:22 by akhercha          #+#    #+#             */
/*   Updated: 2019/02/17 15:59:46 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_str_ends_with(char *str, char *end)
{
	int		i;
	int		j;

	if (!str || !end)
		return (0);
	i = ft_strlen(str) - 1;
	j = ft_strlen(end) - 1;
	while ((str[i] == end[j]) && (str[i] != '\0'))
	{
		i--;
		j--;
	}
	return (j == -1);
}
