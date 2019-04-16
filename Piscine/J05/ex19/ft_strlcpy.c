/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:09:16 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/13 14:09:49 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	j;

	j = 0;
	while (src[j] != '\0' && j < size)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	while (src[j])
		j++;
	return (j);
}
