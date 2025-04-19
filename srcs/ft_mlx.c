/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:02:31 by anass             #+#    #+#             */
/*   Updated: 2025/04/19 03:23:49 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_create_win(t_mlx *mlx)
{
	void	*win;
	int		height;
	int		with;

	height = ft_get_coordinates(mlx->map, 'h', 'y') * IMG_SIZE;
	with = ft_get_coordinates(mlx->map, 'w', 'x') * IMG_SIZE;
	win = mlx_new_window(mlx->mlx, with, height, "so_long");
	return (win);
}

void	ft_return(t_mlx *mlx)
{
	ft_free_map(mlx->map);
	free(mlx->mlx);
	close(mlx->fd);
}

int	get_images(t_mlx *mlx)
{
	t_img	*img;
	int		size;

	img = malloc(sizeof(t_img));
	if (!img)
		return (1);
	img->door = mlx_xpm_file_to_image(mlx->mlx, DOOR_PATH, &size, &size);
	img->floor = mlx_xpm_file_to_image(mlx->mlx, FLOOR_PATH, &size, &size);
	img->key = mlx_xpm_file_to_image(mlx->mlx, KEY_PATH, &size, &size);
	img->wall = mlx_xpm_file_to_image(mlx->mlx, WALL_PATH, &size, &size);
	img->player_up = mlx_xpm_file_to_image(mlx->mlx, UP, &size, &size);
	img->player_right = mlx_xpm_file_to_image(mlx->mlx, RIGHT, &size, &size);
	img->player_left = mlx_xpm_file_to_image(mlx->mlx, LEFT, &size, &size);
	mlx->img = img;
	if (!img->door || !img->floor || !img->key || !img->wall 
		|| !img->player_left || !img->player_right || !img->player_up)
		return (1);
	return (0);
}

int	ft_mlx_init(t_mlx *mlx, char *str)
{
	mlx->fd = open(str, O_RDONLY);
	if (mlx->fd < 0)
		return (1);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (close(mlx->fd), 1);
	mlx->map = ft_get_map(mlx->fd);
	if (!mlx->map)
		return (close(mlx->fd), free(mlx->mlx), 1);
	mlx->keys = ft_key_count(mlx->map);
	if (ft_check_path(mlx))
		return (ft_return(mlx), 1);
	mlx->win = ft_create_win(mlx);
	if (!mlx->win)
		return (ft_return(mlx), 1);
	if(get_images(mlx))
		return (ft_exit(mlx), 1);
	mlx->px = ft_get_coordinates(mlx->map, 'P', 'x');
	mlx->py = ft_get_coordinates(mlx->map, 'P', 'y');
	mlx->collected = 0;
	return (0);
}
