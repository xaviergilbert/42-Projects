/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:48:54 by xgilbert          #+#    #+#             */
/*   Updated: 2018/02/19 15:00:58 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_swap(char *a, char *z)
{
	char swap;

	swap = *a;
	*a = *z;
	*z = swap;
}

char		*ft_strrev(char *str)
{
	int		a;
	int		z;

	z = 0;
	while (str[z])
		z++;
	a = 0;
	z--;
	while (a < z)
	{
		ft_swap(&str[a], &str[z]);
		a++;
		z--;
	}
	return (str);
}
