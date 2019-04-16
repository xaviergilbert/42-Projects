/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 19:28:38 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/06 12:25:21 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	int		resultat;

	if (index < 0)
		resultat = -1;
	if (index == 0)
		resultat = 0;
	if (index == 1)
		resultat = 1;
	if (index > 1)
		resultat = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (resultat);
}
