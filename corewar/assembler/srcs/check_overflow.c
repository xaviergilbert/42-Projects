/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_overflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:52:59 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/13 12:38:34 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char			*check_overflow(t_asm *tasm, char *arg)
{
	int				size;
	char			*tmp;
	int				var;

	var = 0;
	size = 0;
	if (arg[0] == '%' || arg[0] == 'r')
		size++;
	if (!(tmp = ft_itoa_base(ft_atoll(arg + size), 10)))
		free_and_exit(tasm);
	arg[size] == '-' ? var++ : 0;
	while (arg[size + var] && arg[size + var] == '0' && arg[size + var + 1])
		var++;
	tmp[0] == '-' ? ft_strcpy(tmp, &tmp[1]) : 0;
	if (ft_strcmp(&arg[size + var], tmp) != 0)
	{
		tmp ? free(tmp) : 0;
		if (arg[size] == '-')
			!(tmp = ft_strdup("0")) ? free_and_exit(tasm) : 0;
		else
			!(tmp = ft_strdup("ffffffff")) ? free_and_exit(tasm) : 0;
		return (tmp);
	}
	free(tmp);
	return (NULL);
}
