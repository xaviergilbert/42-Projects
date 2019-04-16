/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:06:56 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/13 13:47:21 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int		checkerrors(int fd, char **line)
{
	char			*buffer;
	int				vretour;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (!(buffer = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((vretour = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (!(*line = ft_strjoin1(*line, buffer)))
		{
			free(buffer);
			return (-1);
		}
		ft_bzero(buffer, BUFF_SIZE);
	}
	free(buffer);
	if (vretour == -1)
		return (-1);
	return (1);
}

int				ft_getfile(const int fd, char **line)
{
	if ((checkerrors(fd, line)) == -1)
		return (-1);
	return (1);
}
