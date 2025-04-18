/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arokhsi <arokhsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:17:11 by arokhsi           #+#    #+#             */
/*   Updated: 2025/04/18 16:08:10 by arokhsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_start(t_mlx *mlx)
{
	mlx->player = mlx->img->player_right;
	if (!mlx->player)
		ft_exit(mlx);
	ft_map_gen(mlx);
}

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;

	if (argc != 2 || ft_check_extension(argv[1]))
		return (-1);
	mlx = ft_mlx_init(argv[1]);
	if (!mlx)
		return (-1);
	ft_start(mlx);
	mlx_key_hook(mlx->win, ft_input, mlx);
	mlx_loop_hook(mlx->mlx, ft_animation, mlx);
	mlx_hook(mlx->win, 17, 0, ft_exit, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
