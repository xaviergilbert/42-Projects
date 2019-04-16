/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 19:10:59 by xgilbert          #+#    #+#             */
/*   Updated: 2018/08/16 10:45:51 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		get_extremites(t_liste *liste)
{
	t_element		*element;

	element = liste->premier;
	liste->plus_grand_elem = element;
	liste->plus_petit_elem = element;
	while (element)
	{
		if (element->nombre > liste->plus_grand_elem->nombre)
			liste->plus_grand_elem = element;
		if (element->nombre < liste->plus_petit_elem->nombre)
			liste->plus_petit_elem = element;
		element = element->suivant;
	}
}

void		get_info(t_liste *liste)
{
	t_element		*element;
	int				i;

	if (liste->nb == 0)
		return ;
	element = liste->premier;
	i = 0;
	while (element->suivant)
	{
		i == 1 ? liste->deuxieme_elem = element : 0;
		element = element->suivant;
		i++;
	}
	liste->dernier_elem = element;
	get_extremites(liste);
}

void		get_pos_lst(t_liste *liste)
{
	t_element		*element;
	t_element		*tmp;
	int				i;

	tmp = liste->premier;
	while (tmp)
	{
		i = liste->nb;
		element = liste->premier;
		while (element)
		{
			if (tmp->nombre < element->nombre)
				i--;
			element = element->suivant;
		}
		tmp->pos = i;
		tmp = tmp->suivant;
	}
}
