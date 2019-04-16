/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:27:06 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/20 16:09:46 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fichier.h"

int		mult(int i, int j)
{
	return (i * j);
}

int		add(int i, int j)
{
	return (i + j);
}

int		sous(int i, int j)
{
	return (i - j);
}

int		div(int i, int j)
{
	return (i / j);
}

int		mod(int i, int j)
{
	return (i % j);
}
