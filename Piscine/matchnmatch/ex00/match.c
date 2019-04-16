/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:52:30 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/10 19:22:53 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		case_of_star(char *s1, char *s2, int i, int j)
{
	int		k;

	k = 0;
	if (s1[i] == '\0' && s2[j] == '\0')
		return (1);
	while ((s1[i] != s2[j]) && (s2[j] != '*'))
	{
		if (s1[i] == '\0')
			return (0);
		i++;
		k = j;
		while (s1[i] == s2[k])
		{
			k++;
			i++;
			if (s2[k] == '\0')
				return (1);
		}
	}
	return (0);
}

int		match(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s2[j])
	{
		while (s2[j] == '*')
		{
			j++;
			if (case_of_star(s1, s2, i, j) == 0)
				return (0);
			else
				return (1);
		}
		while (s2[j] == s1[i])
		{
			i++;
			j++;
			if (s2[j] == '\0' && s1[i] == '\0')
				return (1);
		}
	}
	return (0);
}
