/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dellst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 17:45:42 by xgilbert          #+#    #+#             */
/*   Updated: 2018/08/16 10:44:18 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		dellst(t_liste *liste)
{
	t_element		*element;

	if (liste == NULL)
		exit(0);
	while (liste->premier != NULL)
	{
		element = liste->premier;
		liste->premier = liste->premier->suivant;
		free(element);
	}
}
