/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 10:16:18 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/11 13:33:46 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int		i;
	int		nb;
	char	estnegatif;

	i = 0;
	nb = 0;
	estnegatif = 0;
	while (str[i] == '\n' || str[i] == ' ' || str[i] == '\"' || str[i] == '\''
			|| str[i] == '\?' || str[i] == '\\' || str[i] == '\t'
			|| str[i] == '\b' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r')
		i++;
	if (str[i] == '-')
		estnegatif = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (estnegatif == 1)
		return (-nb);
	return (nb);
}
