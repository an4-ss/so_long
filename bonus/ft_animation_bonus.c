/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arokhsi <arokhsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:13:15 by arokhsi           #+#    #+#             */
/*   Updated: 2025/04/19 22:32:12 by arokhsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_sasuke_mov(t_mlx *mlx, char **map)
{
	int			i;
	int			j;
	static int	dir = 1;

	i = -1;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j] != '\n')
		{
			if (map[i][j] == 'B'
				&& (map[i][j + dir] == '0' || map[i][j + dir] == 'P'))
			{
				map[i][j] = '0';
				map[i][j + dir] = 'B';
				j++;
			}
			if (map[mlx->py][mlx->px] == 'B')
			{
				write(1, "You Lost! \n", 11);
				ft_exit(mlx);
			}
		}
	}
	dir *= -1;
}

void	ft_get_frames(t_mlx *mlx)
{
	static int	cur;
	int			size;

	cur++;
	if (cur == 8)
		cur = 0;
	mlx_destroy_image(mlx->mlx, mlx->img->sasuke);
	if (cur == 0)
		mlx->img->sasuke = mlx_xpm_file_to_image(mlx->mlx, F1, &size, &size);
	else if (cur == 1)
		mlx->img->sasuke = mlx_xpm_file_to_image(mlx->mlx, F2, &size, &size);
	else if (cur == 2)
		mlx->img->sasuke = mlx_xpm_file_to_image(mlx->mlx, F3, &size, &size);
	else if (cur == 3)
		mlx->img->sasuke = mlx_xpm_file_to_image(mlx->mlx, F4, &size, &size);
	else if (cur == 4)
		mlx->img->sasuke = mlx_xpm_file_to_image(mlx->mlx, F5, &size, &size);
	else if (cur == 5)
		mlx->img->sasuke = mlx_xpm_file_to_image(mlx->mlx, F6, &size, &size);
	else if (cur == 6)
		mlx->img->sasuke = mlx_xpm_file_to_image(mlx->mlx, F7, &size, &size);
	else if (cur == 7)
		mlx->img->sasuke = mlx_xpm_file_to_image(mlx->mlx, F8, &size, &size);
	if (!mlx->img->sasuke)
	{
		write(2, "ERROR : Missing compenents\n", 27);
		ft_exit(mlx);
	}
}

int	ft_animation(t_mlx *mlx)
{
	static int	i = 1;
	int			anim_speed;
	int			sasuke_mv_speed;

	anim_speed = 7900;
	sasuke_mv_speed = 38700;
	if (i % anim_speed == 0)
	{
		ft_mov(mlx, 0);
		ft_get_frames(mlx);
	}
	if (i % sasuke_mv_speed == 0)
		ft_sasuke_mov(mlx, mlx->map);
	if (i == anim_speed * 1000)
		i = 1;
	i++;
	return (0);
}
