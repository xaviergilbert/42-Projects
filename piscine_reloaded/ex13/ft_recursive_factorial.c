/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:23:10 by xgilbert          #+#    #+#             */
/*   Updated: 2017/11/06 15:25:32 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int		resultat;

	if (nb > 12 || nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	resultat = nb * ft_recursive_factorial(nb - 1);
	return (resultat);
}
