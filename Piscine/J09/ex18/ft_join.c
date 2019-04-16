/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:40:52 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/08 15:05:17 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_len(char **tab)
{
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 0;
	while (tab[j][i])
	{
		while (tab[j][i])
		{
			length++;
			i++;
		}
		length++;
		j++;
	}
	return (length);
}

char	*ft_join(char **tab, char *sep)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	*array;

	len = ft_len(tab);
	array = (char*)malloc(sizeof(*tab) * len);
	i = 0;
	j = 0;
	k = 0;
	while (tab[j][i])
	{
		while (tab[j][++i])
		{
			array[k] = tab[j][i];
			k++;
		}
		array[k] = sep[j];
		i = 0;
		j++;
		k++;
	}
	array[k] = '\0';
	return (array);
}
