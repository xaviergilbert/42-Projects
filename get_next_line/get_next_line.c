/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:06:56 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/16 18:38:40 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static int		checkerrors(int fd, char **str, char **line)
{
	char			*buffer;
	int				vretour;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || fd > OPEN_MAX)
		return (-1);
	if (!*str)
		*str = ft_strnew(1);
	buffer = ft_strnew(BUFF_SIZE);
	while ((vretour = read(fd, buffer, BUFF_SIZE)) >= 0)
	{
		*str = ft_strjoin1(*str, buffer);
		if (char_in_str(buffer, '\n') || vretour == 0)
			break;
	}
	free(buffer);
	if (vretour == -1)
		return (-1);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str[OPEN_MAX];

	if ((checkerrors(fd, &str[fd], line)) == -1)
		return (-1);
	if (str[fd][0] == '\0')
	{
		free(str[fd]);
		return (0);
	}
	else if (char_in_str(str[fd], '\n'))
	{
		*line = ft_strndup(str[fd], ft_strlen(str[fd]) -
		ft_strlen(ft_strstr(str[fd], "\n")));
		str[fd] = ft_strcpy(str[fd], ft_strstr(str[fd], "\n") + 1);
		return (1);
	}
	*line = ft_strdup(str[fd]);
	str[fd][0] = '\0';
	return (1);
}
