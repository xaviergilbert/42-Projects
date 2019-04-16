/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 17:34:15 by xgilbert          #+#    #+#             */
/*   Updated: 2018/06/21 19:28:03 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_info(const char *format, t_format *s)
{
	int		i;
	char	*temp;

	i = s->k;
	get_conv(&format[s->k], s);
	while (format[i] != s->conv && format[i])
		i++;
	if (format[i] == '\0')
	{
		ft_putendl("Veuillez preciser un format de conversion svp...");
		exit(0);
	}
	temp = ft_strndup(&format[s->k], i - s->k + 1);
	get_modifier(temp, s);
	get_precision(temp, s);
	get_attribut(temp, s);
	free(temp);
}

void		get_conv(const char *str, t_format *s)
{
	char	*temp;
	int		i;
	int		j;

	temp = ft_strdup("sSpdDioOuUxXcC%");
	i = 0;
	while (str[i])
	{
		j = 0;
		while (temp[j])
		{
			if (str[i] == temp[j])
			{
				s->conv = temp[j++];
				free(temp);
				return ;
			}
			else
				j++;
		}
		i++;
	}
	free(temp);
}

void		get_modifier(char *str, t_format *s)
{
	int		i;

	i = ft_strlen(str) - 2;
	if (str[i] == 'l' && str[i - 1] == 'l')
		s->modifier = MDF_LL;
	else if (str[i] == 'h' && str[i - 1] == 'h')
		s->modifier = MDF_HH;
	else if (str[i] == 'h')
		s->modifier = MDF_H;
	else if (str[i] == 'l')
		s->modifier = MDF_L;
	else if (str[i] == 'j')
		s->modifier = MDF_J;
	else if (str[i] == 'z')
		s->modifier = MDF_Z;
	s->conv == 'o' || s->conv == 'O' ? s->base = 8 : 0;
	s->conv == 'x' || s->conv == 'X' ? s->base = 16 : 0;
	s->conv == 'u' || s->conv == 'U' ? s->base = 10 : 0;
}

void		get_attribut(char *str, t_format *s)
{
	int		i;

	i = 0;
	while ((str[i] < '0' || str[i] > '9') && str[i])
		i++;
	if (char_in_str(str, '-'))
		s->att_moins = 1;
	if (char_in_str(str, '+'))
		s->att_plus = 1;
	if (char_in_str(str, '#'))
		s->att_diese = 1;
	if (str[i] == '0' && s->att_moins != 1 && s->precision == 0)
		s->att_zero = 1;
	if (char_in_str(str, ' ') && !(s->att_plus))
		s->att_esp = 1;
}

void		get_precision(char *str, t_format *s)
{
	int		i;

	i = 0;
	if (char_in_str(str, '.'))
		s->precision = 1;
	if (s->precision == 1)
		s->att_zero = 0;
	while (str[i] != '.' && str[i])
		i++;
	if (str[i] == '.' && (str[i + 1] < '1' || str[i + 1] > '9'))
		s->precision = 2;
	if (s->conv == '%')
		s->precision = 0;
}
