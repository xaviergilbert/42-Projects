/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_champs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:42:15 by akhercha          #+#    #+#             */
/*   Updated: 2019/03/08 05:39:55 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			get_nb_champs(t_champ *champ_array)
{
	int		nb;

	nb = 0;
	while ((nb < MAX_PLAYERS) && (champ_array[nb].id != -1))
		nb++;
	return (nb);
}
