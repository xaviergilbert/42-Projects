/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fichier.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:23:05 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/20 17:26:51 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FICHIER_H
# define FICHIER_H

# include <unistd.h>

typedef struct	s_doop
{
	char	car;
	int		(*fonction)(int, int);
}				t_doop;

int				ft_atoi(char *str);
void			ft_putnbr(int nb);
void			ft_putchar(char c);
void			ft_putstr(char *str);
int				mult(int i, int j);
int				add(int i, int j);
int				sous(int i, int j);
int				div(int i, int j);
int				mod(int i, int j);

#endif
