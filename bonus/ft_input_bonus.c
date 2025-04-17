/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arokhsi <arokhsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:14:29 by arokhsi           #+#    #+#             */
/*   Updated: 2025/04/17 15:14:31 by arokhsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_mov(t_mlx *mlx, int direction)
{
	ft_map_gen(mlx);
	if (direction == W_KEY)
		mlx->player = mlx->img->player_up;
	else if (direction == S_KEY)
		mlx->player = mlx->img->player_right;
	else if (direction == A_KEY)
		mlx->player = mlx->img->player_left;
	else if (direction == D_KEY)
		mlx->player = mlx->img->player_right;
	ft_mlx_print_img(mlx, mlx->player, mlx->px, mlx->py);
}

static int	ft_can_mov(t_mlx *mlx, int x, int y)
{
	int	obg;

	obg = mlx->map[y][x];
	if (obg == '1' || (obg == 'E' && mlx->collected == 0))
		return (0);
	else
		mlx->steps++;
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
	if (current == 'B')
	{
		write(1, "YOU LOST!!\n", 11);
		ft_exit(mlx);
	}
}

int	ft_input(int keycode, t_mlx *mlx)
{
	if (keycode == ESC_KEY)
		ft_exit(mlx);
	else if (keycode == W_KEY && ft_can_mov(mlx, mlx->px, mlx->py - 1))
		mlx->py -= 1;
	else if (keycode == S_KEY && ft_can_mov(mlx, mlx->px, mlx->py + 1))
		mlx->py += 1;
	else if (keycode == A_KEY && ft_can_mov(mlx, mlx->px - 1, mlx->py))
		mlx->px -= 1;
	else if (keycode == D_KEY && ft_can_mov(mlx, mlx->px + 1, mlx->py))
		mlx->px += 1;
	ft_mov(mlx, keycode);
	ft_event(mlx, mlx->px, mlx->py);
	return (0);
}
