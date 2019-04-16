/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:34:09 by xgilbert          #+#    #+#             */
/*   Updated: 2017/12/19 16:39:39 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

int		main(int argc, char **argv)
{
	char	buffer[1];
	int		filein;
	int		nbread;

	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (0);
	}
	if (argc == 1)
	{
		ft_putstr("File name missing.\n");
		return (0);
	}
	filein = open(argv[1], O_RDONLY);
	nbread = read(filein, buffer, 1);
	while (nbread > 0)
	{
		write(1, buffer, nbread);
		nbread = read(filein, buffer, 1);
	}
	close(filein);
	return (0);
}
