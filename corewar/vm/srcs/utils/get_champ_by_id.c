/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_champ_by_id.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:57:05 by akhercha          #+#    #+#             */
/*   Updated: 2019/03/30 15:11:52 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_champ		*get_champ_by_id(t_champ *champ_array, int id)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (champ_array[i].id == id)
			return (&(champ_array[i]));
		i++;
	}
	return (NULL);
}
