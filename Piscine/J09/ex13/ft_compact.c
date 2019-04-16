/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 10:41:34 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/08 14:36:06 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_compact(char **tab, int length)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	*array;

	*tab = (char*)malloc(sizeof(**tab) * (length + 1));
	i = 0;
	j = 0;
	while (l < length)
	{
		while (tab[k][i])
		{
			l++;
			if (tab[k][i] == '0')
				i++;
			array[j] = tab[k][i];
			i++;
			j++;
		}
		k++;
		i = 0;
	}
	array[j] = '\0';
	return (j);
}
