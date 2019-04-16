/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:47:37 by xgilbert          #+#    #+#             */
/*   Updated: 2018/02/27 14:29:08 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

char	*ft_strrev(char *str)
{
	int		a;
	int		z;

	z = 0;
	while (str[z])
		z++;
	z--;
	a = 0;
	while (a < z)
	{
		ft_swap(&str[a], &str[z]);
		a++;
		z--;
	}
	return (str);
}
