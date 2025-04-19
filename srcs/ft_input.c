/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 12:19:06 by anass             #+#    #+#             */
/*   Updated: 2025/04/19 03:26:55 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_mov(t_mlx *mlx, int x, int y, int direction)
{
	ft_map_gen(mlx);
	if (direction == W_KEY)
		ft_mlx_print_img(mlx, mlx->img->player_up, x, y);
	else if (direction == S_KEY)
		ft_mlx_print_img(mlx, mlx->img->player_right, x, y);
	else if (direction == A_KEY)
		ft_mlx_print_img(mlx, mlx->img->player_left, x, y);
	else if (direction == D_KEY)
		ft_mlx_print_img(mlx, mlx->img->player_right, x, y);
	else
		ft_mlx_print_img(mlx, mlx->img->player_right, x, y);
}

static int	ft_can_mov(t_mlx *mlx, int x, int y)
{
	int			obg;
	static int	steps;

	obg = mlx->map[y][x];
	if (obg == '1' || (obg == 'E' && mlx->collected == 0))
		return (0);
	else
	{
		ft_putnbr(++steps);
		write (1, "\n", 1);
	}
	return (1);
}

static	void	ft_event(t_mlx *mlx, int px, int py)
{
	int	current;

	current = mlx->map[py][px];
	if (current == 'C')
	{
		mlx->map[py][px] = '0';
		mlx->keys--;
	}
	if (mlx->keys == 0)
		mlx->collected = 1;
	if ((current == 'E' && mlx->collected == 1))
	{
		write(1, "YOU WON!!\n", 10);
		ft_exit(mlx);
	}
}

int	ft_input(int keycode, t_mlx *mlx)
{
	static int	xpo;
	static int	ypo;

	if (xpo == 0 && ypo == 0)
	{
		xpo = mlx->px;
		ypo = mlx->py;
	}
	if (keycode == ESC_KEY)
		ft_exit(mlx);
	else if (keycode == W_KEY && ft_can_mov(mlx, xpo, ypo - 1))
		ypo -= 1;
	else if (keycode == S_KEY && ft_can_mov(mlx, xpo, ypo + 1))
		ypo += 1;
	else if (keycode == A_KEY && ft_can_mov(mlx, xpo - 1, ypo))
		xpo -= 1;
	else if (keycode == D_KEY && ft_can_mov(mlx, xpo + 1, ypo))
		xpo += 1;
	ft_mov(mlx, xpo, ypo, keycode);
	ft_event(mlx, xpo, ypo);
	return (0);
}
