/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_id_exists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:42:15 by akhercha          #+#    #+#             */
/*   Updated: 2019/02/19 16:56:49 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			champ_id_exists(t_champ *champ_array, int id)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (champ_array[i].id == id)
			return (1);
		i++;
	}
	return (0);
}
