/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:06:56 by xgilbert          #+#    #+#             */
/*   Updated: 2018/08/17 15:29:41 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Gestion cas d'erreur et malloc des chaines str et buffer
*/

static int		checkerrors(int fd, char **str, char **line, char **buffer)
{
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || fd > OPEN_MAX)
		return (0);
	if (!*str)
		*str = ft_strnew(1);
	*buffer = ft_strnew(BUFF_SIZE);
	return (1);
}

/*
** On lit tout le buffer et on copie colle tout dans la variable static str
*/

static int		create_str(int fd, char **str, int vretour, char *buffer)
{
	int				k;

	while (vretour > 0)
	{
		buffer[vretour] = '\0';
		*str = ft_strjoin1(*str, buffer);
		k = -1;
		while (buffer[++k])
		{
			if (buffer[k] == '\n')
				return (0);
		}
		vretour = read(fd, buffer, BUFF_SIZE);
	}
	return (0);
}

/*
** On copie les k caracteres precedant le '\n' dans line
** str devient &str[k]
*/

static void		cpy(char **line, char *str, int k)
{
	*line = ft_strndup(str, k);
	str = ft_strcpy(str, &str[k]);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str[OPEN_MAX];
	char			*buffer;
	int				k;

	if ((checkerrors(fd, &str[fd], line, &buffer)) == 0
	|| (k = read(fd, buffer, BUFF_SIZE)) == -1)
		return (-1);
	create_str(fd, &str[fd], k, buffer);
	free(buffer);
	k = -1;
	while (str[fd][++k])
	{
		if (str[fd][k] == '\n')
		{
			str[fd][k++] = '\0';
			cpy(line, str[fd], k);
			return (1);
		}
	}
	if (str[fd][0] == '\0')
		return (0);
	cpy(line, str[fd], k);
	return (1);
}
