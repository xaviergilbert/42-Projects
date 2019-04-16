/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 11:24:02 by alanter           #+#    #+#             */
/*   Updated: 2018/09/19 02:34:38 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include <limits.h>
# include <math.h>
# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define WIN_W 1350
# define WIN_H 780

typedef struct	s_stk
{
	int		*stk_a;
	int		*stk_b;
	int		top_a;
	int		top_b;
	int		nb_values;
	char	*inst;
	int		option;
	int		arg;
	int		max;
	int		size;
	int		visual;
}				t_stk;

typedef struct	s_img
{
	void			*img_ptr;
	unsigned int	*img;
	int				size_l;
	int				bpp;
	int				endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
	t_stk		stk;
	int			speed;
	int			ok;
	int			print_ok;
	int			nb_inst;
	int			menu;
	int			val_h;
	int			a_back;
	int			b_back;
	int			a_p;
	int			a_n;
	int			b_p;
	int			b_n;
}				t_mlx;

void			*window(t_stk stk);
void			inst(char *inst_in, t_stk *stk);
void			ft_swap(int *stack, int size);
void			ft_rotate(int *stack, int size);
void			ft_rev_rotate(int *stack, int size);
void			ft_push(int *src, int *dst, int *top_s, int *top_d);
int				init_t_stk(t_stk *stk, int argc, char **argv);
void			draw_str(t_mlx *mlx);
void			draw_back(unsigned int *img, t_mlx *mlx);
void			draw_stkb(unsigned int *img, t_stk stk, int val_h, t_mlx *mlx);
void			draw_stka(unsigned int *img, t_stk stk, int top, t_mlx *mlx);
void			colors(int key, t_mlx *mlx);
void			colorfull(t_mlx *mlx);
void			inst(char *inst_in, t_stk *stk);
void			ft_new_image(t_mlx *mlx, t_stk stk, int val_h);
int				sorted(t_stk *stk, int size);

#endif
