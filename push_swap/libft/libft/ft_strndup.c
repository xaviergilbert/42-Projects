/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:43:44 by xgilbert          #+#    #+#             */
/*   Updated: 2018/01/31 18:46:41 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *str, int k)
{
	char	*cpy;

	if (!(cpy = ft_strnew(k + 1)))
		return (0);
	ft_strncpy(cpy, str, k);
	return (cpy);
}
