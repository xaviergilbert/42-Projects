/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initlst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:22:20 by xgilbert          #+#    #+#             */
/*   Updated: 2018/08/16 10:46:16 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_liste		*initlst(t_liste *liste, int nb)
{
	t_element		*element;

	if (liste == NULL)
		exit(0);
	if (!(element = (t_element*)malloc(sizeof(*element))))
		return (NULL);
	element->nombre = nb;
	element->suivant = NULL;
	liste->premier = element;
	return (liste);
}
