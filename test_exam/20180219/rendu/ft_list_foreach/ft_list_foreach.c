/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:53:32 by xgilbert          #+#    #+#             */
/*   Updated: 2018/02/19 16:11:06 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list		*list_ptr;

	begin_list = list_ptr;
	while (list_ptr->data)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}
