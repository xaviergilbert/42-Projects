/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes_to_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:03:57 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/13 12:29:38 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int		create_file(char *dot_cor_filename)
{
	int				fd;

	fd = open(dot_cor_filename, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd <= 0)
		return (-1);
	return (fd);
}

static void		replace_s_by_cor(char **dot_cor_filename, int dot_s_len)
{
	int			i;

	i = dot_s_len - 1;
	(*dot_cor_filename)[i++] = 'c';
	(*dot_cor_filename)[i++] = 'o';
	(*dot_cor_filename)[i] = 'r';
}

int				bytes_to_file(t_asm *tasm, char *dot_s_filename)
{
	char			*dot_cor_filename;
	size_t			dot_s_len;
	size_t			dot_cor_len;
	int				dot_cor_fd;

	dot_s_len = ft_strlen(dot_s_filename);
	dot_cor_len = dot_s_len + 2;
	if (!(dot_cor_filename = ft_strnew(dot_cor_len)))
		return (1);
	dot_cor_filename = ft_strncpy(dot_cor_filename, dot_s_filename, dot_s_len);
	replace_s_by_cor(&dot_cor_filename, (int)dot_s_len);
	if ((dot_cor_fd = create_file(dot_cor_filename)) > 0)
	{
		write_in_file(tasm, dot_cor_fd);
		ft_printf("'%s' was successfully created.\n", dot_cor_filename);
		close(dot_cor_fd);
	}
	ft_strdel(&dot_cor_filename);
	return (!(dot_cor_fd > 0));
}
