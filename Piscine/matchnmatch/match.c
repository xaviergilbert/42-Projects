/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:52:30 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/11 19:05:42 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		match(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	j = 0;
	k = 0;
	while (s2[j])
	{
		while (s2[j] == '*')
		{
			printf("%d,%d,%d, %s\n", i, j, k, "s2[j] == *");
			j++;
			if (s1[i] == '\0' && s2[j] == '\0')
				return (1);
			while ((s1[i] != s2[j]) && (s2[j] != '*'))
			{
				if (s1[i] == '\0')
					return (0);
				printf("%d,%d,%d, %s\n", i, j, k, "les chaines matches pas");
				i++;
				k = j;
				/*if (s1[i] == s2[j])
				{
					k = j;
					printf("%d,%d,%d, %s\n", i, j, k, "premier s1[i] match avec s2[k]");
				}*/
				while (s1[i] == s2[k])
				{
					k++;
					i++;
					printf("%d,%d,%d, %s\n", i, j, k, "on incremente les deux chaines matches");
					if (s2[k] == '\0')
						return (1);
				}
			}
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

/*
int		match_test(char *s1, char *s2)
{
	int		i;
	int		j;

	while (s1[i] || s2[j])
	{
		if (s2[j] == '*' && s1[i] != '\0')
	
*/

int		match_recursive(char *s1, char *s2)
{
	if (*s2 == '*' && *s1 != '\0')
		return (match_recursive(s1 + 1, s2) || match_recursive(s1, s2 + 1));
	if (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
		return (match_recursive(s1 + 1, s2 + 1 ));
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s2 == '*' && *s1 == '\0')
		return (match_recursive(s1, s2 + 1));
	return (0);
}

#include <stdio.h>

int		main(int argc, char **argv)
{
	printf("%d\n", match(argv[1], argv[2]));
	printf("%d\n", match_recursive(argv[1], argv[2]));
	return (0);
}

//on parcourt s2
//to_find = s2 entre chaque etoile
//
