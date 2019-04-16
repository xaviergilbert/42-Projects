/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_big_endian.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:43:12 by akhercha          #+#    #+#             */
/*   Updated: 2019/03/30 15:12:04 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					to_big_endian(unsigned int lil_endian)
{
	t_mem			*little;
	t_mem			*big;
	unsigned int	rsp;

	little = (t_mem*)&lil_endian;
	big = (t_mem*)&rsp;
	big[0] = little[3];
	big[1] = little[2];
	big[2] = little[1];
	big[3] = little[0];
	return (rsp);
}
