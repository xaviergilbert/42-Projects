/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 16:21:00 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/13 14:08:41 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	lendest;
	unsigned int	lensrc;

	lendest = 0;
	lensrc = 0;
	while (dest[lendest])
		lendest++;
	while (src[lensrc] != '\0' && (lensrc + lendest < size))
	{
		dest[lendest + lensrc] = src[lensrc];
		lensrc++;
	}
	dest[lendest + lensrc] = '\0';
	while (src[lensrc])
		lensrc++;
	return (size + lensrc);
}
