/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:30:44 by xgilbert          #+#    #+#             */
/*   Updated: 2018/08/16 10:46:34 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void			insertlst(t_liste *liste, int nb)
{
	t_element			*nouveau;

	nouveau = (t_element*)malloc(sizeof(*nouveau));
	nouveau->nombre = nb;
	nouveau->suivant = liste->premier;
	liste->premier = nouveau;
}
