/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 12:56:05 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/18 11:42:17 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

typedef int		t_bool;
# define EVEN_MSG	"I have an even number of arguments.\n"
# define ODD_MSG		"I have an odd number of arguments.\n"
# define TRUE	1
# define FALSE	2
# define SUCCESS		0
# define EVEN(nbr) (nbr - 1) % 2 != 0

#endif
