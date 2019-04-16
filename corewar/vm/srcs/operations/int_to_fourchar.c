/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_fourchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <mcaseaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/02/25 16:57:48 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		int_to_fourchar(int reg, t_mem *arena, int index)
{
	arena[index % MEM_SIZE] = (char)(reg >> 24 & 0xff);
	arena[(index + 1) % MEM_SIZE] = (char)(reg >> 16 & 0xff);
	arena[(index + 2) % MEM_SIZE] = (char)(reg >> 8 & 0xff);
	arena[(index + 3) % MEM_SIZE] = (char)(reg & 0xff);
}
