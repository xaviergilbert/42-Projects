/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 17:11:35 by alanter           #+#    #+#             */
/*   Updated: 2018/09/19 18:12:12 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	colorfull(t_mlx *mlx)
{
	mlx->a_back = 0xFEBDC0;
	mlx->b_back = 0xB3E5EE;
	mlx->a_p = 0xFB5100;
	mlx->a_n = 0xFB515D;
	mlx->b_p = 0x44B2C7;
	mlx->b_n = 0x44B2D7;
}

void	blackwhite(t_mlx *mlx)
{
	mlx->a_back = 0xC7C7C7;
	mlx->b_back = 0x7C7B7B;
	mlx->a_p = 0x3C2B28;
	mlx->a_n = 0xFFFFFF;
	mlx->b_p = 0x3C2B28;
	mlx->b_n = 0xFFFFFF;
}

void	psyche(t_mlx *mlx)
{
	mlx->a_back = rand();
	mlx->b_back = rand();
	mlx->a_p = rand();
	mlx->a_n = rand();
	mlx->b_p = rand();
	mlx->b_n = rand();
}

void	negative(t_mlx *mlx)
{
	mlx->a_back = 0XFFFFFF - mlx->a_back;
	mlx->b_back = 0XFFFFFF - mlx->b_back;
	mlx->a_p = 0XFFFFFF - mlx->a_p;
	mlx->a_n = 0XFFFFFF - mlx->a_n;
	mlx->b_p = 0XFFFFFF - mlx->b_p;
	mlx->b_n = 0XFFFFFF - mlx->b_n;
}

void	colors(int key, t_mlx *mlx)
{
	if (key == 18 || key == 83)
		colorfull(mlx);
	if (key == 19 || key == 84)
		blackwhite(mlx);
	if (key == 20 || key == 85)
		psyche(mlx);
	if (key == 21 || key == 86)
		negative(mlx);
	ft_new_image(mlx, mlx->stk, mlx->val_h);
}
