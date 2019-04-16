/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:43:19 by lucdubos          #+#    #+#             */
/*   Updated: 2019/04/13 13:02:03 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			ft_pow_2(int nb)
{
	int		ret;

	ret = 1;
	while (nb > 1)
	{
		ret = ret * 2;
		nb--;
	}
	return (ret);
}

char		*ft_binary_to_hexa(char *binary)
{
	int		i;
	int		nbr;
	int		j;

	j = 0;
	nbr = 0;
	i = ft_strlen(binary);
	while (i >= 0)
	{
		if (binary[i] == '1')
			nbr = nbr + ft_pow_2(j);
		j++;
		i--;
	}
	free(binary);
	return (ft_itoa_base(nbr, 16));
}

char		*ft_strjoin1_size(char *dst, char *src, int size)
{
	char	*tmp;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!(tmp = ft_strnew(ft_strlen(dst) + ft_strlen(src) + 1)))
	{
		free(dst);
		return (NULL);
	}
	while (i < size)
		tmp[i++] = dst[j++];
	while (src[k])
		tmp[i++] = src[k++];
	while (dst[j])
		tmp[i++] = dst[j++];
	tmp[i] = '\0';
	free(dst);
	return (tmp);
}

int			hexa_to_good_size_hexa(char **tmp, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (ft_strlen(*tmp) < size * 2)
	{
		if (!(*tmp = ft_strjoin2("0", *tmp)))
			return (0);
	}
	while (i < size * 2)
	{
		if (i % 2 == 0 && i > 0)
		{
			if (!(*tmp = ft_strjoin1_size(*tmp, " ", i + j)))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			size_by_type_instruction(int type)
{
	int		size;

	size = 0;
	if (type == REG_CODE)
		size = 1;
	else if (type == DIR_CODE)
		size = DIR_SIZE;
	else
		size = IND_SIZE;
	return (size);
}
