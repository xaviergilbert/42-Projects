/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 04:25:21 by alanter           #+#    #+#             */
/*   Updated: 2018/09/19 03:06:04 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	menu(t_mlx *mlx, int c)
{
	if (mlx->menu == 0)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W - 120, 5, c, "M   : Menu");
	if (mlx->menu == 1)
	{
		mlx_string_put(mlx->mlx_ptr,
				mlx->win, WIN_W - 190, 5, c, "M   : Close");
		mlx_string_put(mlx->mlx_ptr,
				mlx->win, WIN_W - 190, 25, c, "->  : Speed up");
		mlx_string_put(mlx->mlx_ptr,
				mlx->win, WIN_W - 190, 45, c, "<-  : Speed down");
		mlx_string_put(mlx->mlx_ptr,
				mlx->win, WIN_W - 190, 65, c, "1   : Colorfull");
		mlx_string_put(mlx->mlx_ptr,
				mlx->win, WIN_W - 190, 85, c, "2   : Black&white");
		mlx_string_put(mlx->mlx_ptr,
				mlx->win, WIN_W - 190, 105, c, "3   : Random");
		mlx_string_put(mlx->mlx_ptr,
				mlx->win, WIN_W - 190, 125, c, "4   : Negative");
		mlx_string_put(mlx->mlx_ptr,
				mlx->win, WIN_W - 190, 145, c, "Esc : Quit");
	}
	if (mlx->print_ok == 1 && sorted(&mlx->stk, mlx->stk.size) == 1)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 2, WIN_H / 2, c, "OK");
	else if (mlx->print_ok == 1 && sorted(&mlx->stk, mlx->stk.size) == -1)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 2, WIN_H / 2, c, "KO");
}

void	draw_str(t_mlx *mlx)
{
	int		c;
	char	*nb_i;

	c = 0x000040;
	nb_i = ft_itoa(mlx->nb_inst);
	mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W - 70, WIN_H - 30, c, nb_i);
	free(nb_i);
	mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 4 - 5, 10, c, "STK_A");
	mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W * 3 / 4 - 5, 10, c, "STK_B");
	if (mlx->speed < 5)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X100000");
	else if (mlx->speed < 50)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X10000");
	else if (mlx->speed < 500)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X1000");
	else if (mlx->speed < 5000)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X100");
	else if (mlx->speed < 50000)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X10");
	else if (mlx->speed < 500000)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X1");
	else if (mlx->speed < 5000000)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X0.1");
	mlx->stk.size = mlx->stk.top_a + mlx->stk.top_b + 2;
	menu(mlx, c);
}

void	draw_back(unsigned int *img, t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < WIN_W)
	{
		while (y < WIN_H)
		{
			if ((x < WIN_W / 2))
				img[y * WIN_W + x] = mlx->a_back;
			else
				img[y * WIN_W + x] = mlx->b_back;
			y++;
		}
		x++;
		y = 0;
	}
}

void	draw_stkb(unsigned int *img, t_stk stk, int val_h, t_mlx *mlx)
{
	int x;
	int y;
	int val_w;

	y = -1;
	while (++y < WIN_H)
	{
		x = WIN_W / 2 - 1;
		while (++x < WIN_W)
		{
			if (stk.top_b > 0)
				val_w = abs(stk.stk_b[stk.top_b] * WIN_W / 2 / stk.max);
			val_w = (val_w == 0) ? 1 : val_w;
			if (y > WIN_H - ((stk.top_b + 1) * val_h) && x - WIN_W / 2 < val_w)
			{
				if (stk.stk_b[stk.top_b] > 0)
					img[y * WIN_W + (x + (WIN_W / 2 - val_w) / 2)] = mlx->b_p;
				else
					img[y * WIN_W + (x + (WIN_W / 2 - val_w) / 2)] = mlx->b_n;
			}
			if (y > WIN_H - ((stk.top_b) * val_h) && stk.top_b > 0)
				stk.top_b -= 1;
		}
	}
}

void	draw_stka(unsigned int *img, t_stk stk, int top, t_mlx *mlx)
{
	int x;
	int y;
	int val_w;

	x = -1;
	y = -1;
	while (++y < WIN_H && x < WIN_W / 2)
	{
		while (++x < WIN_W)
		{
			val_w = abs(stk.stk_a[top] * WIN_W / 2 / stk.max);
			val_w = (val_w == 0) ? 1 : val_w;
			if (y > WIN_H - ((top + 1) * mlx->val_h) && x < val_w)
			{
				if (stk.stk_a[top] < 0)
					img[y * WIN_W + (x + ((WIN_W / 2 - val_w) / 2))] = mlx->a_n;
				else
					img[y * WIN_W + (x + ((WIN_W / 2 - val_w) / 2))] = mlx->a_p;
			}
			if (y > WIN_H - ((top) * mlx->val_h))
				top -= 1;
		}
		x = -1;
	}
}
