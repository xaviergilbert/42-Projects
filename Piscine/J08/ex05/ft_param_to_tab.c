/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 16:13:30 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/19 14:47:29 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int				ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strdup(char *src)
{
	int				len;
	int				i;
	char			*cpy;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	cpy = (char*)malloc(sizeof(*cpy) * (len + 1));
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

t_stock_par		*ft_param_to_tab(int ac, char **av)
{
	t_stock_par		*arr;
	int				j;

	j = 0;
	arr = (t_stock_par*)malloc(sizeof(*arr) * ac * 4 + 1);
	while (j < ac)
	{
		arr[j].size_param = ft_strlen(av[j]);
		arr[j].str = av[j];
		arr[j].copy = ft_strdup(av[j]);
		arr[j].tab = ft_split_whitespaces(av[j]);
		j++;
	}
	arr[j].str = 0;
	return (arr);
}
