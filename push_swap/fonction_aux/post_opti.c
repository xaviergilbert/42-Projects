/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_opti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 15:29:24 by xgilbert          #+#    #+#             */
/*   Updated: 2018/09/13 18:55:49 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void			condition(t_struct *s, char **tmp, int *w, int nw)
{
	if ((ft_strcmp(tmp[*w], "ra") == 0 && ft_strcmp(tmp[nw], "rb") == 0)
	|| (ft_strcmp(tmp[*w], "rb") == 0 && ft_strcmp(tmp[nw], "ra") == 0))
	{
		tmp[*w] = ft_strcpy(tmp[*w], "rr");
		tmp[nw] = ft_memset(tmp[nw], '\0', ft_strlen(tmp[nw]));
		*w = 0;
		s->nb_coups--;
	}
	else if ((ft_strcmp(tmp[*w], "pa") == 0 && ft_strcmp(tmp[nw], "pb") == 0)
	|| (ft_strcmp(tmp[*w], "pb") == 0 && ft_strcmp(tmp[nw], "pa") == 0))
	{
		tmp[*w] = ft_memset(tmp[*w], '\0', ft_strlen(tmp[*w]));
		tmp[nw] = ft_memset(tmp[nw], '\0', ft_strlen(tmp[nw]));
		*w = 0;
		s->nb_coups = s->nb_coups - 2;
	}
	else
		*w = *w + 1;
}

char			**post_opti(t_struct *s)
{
	char		**tmp;
	int			w;
	int			nw;

	tmp = ft_strsplit(s->str, '\n');
	w = 0;
	while (tmp[w])
	{
		while (tmp[w][0] == '\0')
			w++;
		nw = w + 1;
		while (tmp[nw] && tmp[nw][0] == '\0')
			nw++;
		if (tmp[nw] == NULL)
			break;
		condition(s, tmp, &w, nw);
	}
	return (tmp);
}
