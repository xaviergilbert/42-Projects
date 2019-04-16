/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 13:19:24 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/08 15:11:40 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_unmatch(int *tab, int length)
{
	int		i;
	int		p;

	i = 0;
	p = 1;
	while (i < length)
	{
		while ((tab[i] != tab[p]) || ((i == p) && tab[i] == tab[p]))
		{
			if (p == length - 1)
				return (tab[i]);
			p++;
		}
		if (tab[i] == tab[p])
		{
			tab[i] = 25464;
			tab[p] = 25464;
		}
		p = 0;
		i++;
	}
	return (0);
}
