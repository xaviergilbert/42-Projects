/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 20:21:47 by xgilbert          #+#    #+#             */
/*   Updated: 2017/09/07 08:38:22 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(-2);
		ft_putnbr(147483648);
	}
	if (nb < 0 && nb != -2147483648)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	if (nb >= 0)
		ft_putchar((nb % 10) + '0');
}
