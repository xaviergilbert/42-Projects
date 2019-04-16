/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 13:03:01 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/11 13:35:00 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (str[i])
	{
		j = 0;
		k = 0;
		if (str[i] == to_find[j])
			k = i;
		while (str[k] == to_find[j])
		{
			k++;
			j++;
			if (to_find[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
