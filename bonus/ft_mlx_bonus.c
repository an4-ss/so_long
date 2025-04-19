/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:16:52 by arokhsi           #+#    #+#             */
/*   Updated: 2025/04/19 03:41:13 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

t_mlx	*ft_mlx_init(char *str)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->fd = open(str, O_RDONLY);
	if (mlx->fd < 0)
		return (free(mlx), NULL);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (close(mlx->fd), free(mlx), NULL);
	mlx->map = ft_get_map(mlx->fd);
	if (!mlx->map)
		return (free(mlx->mlx), close(mlx->fd), free(mlx), NULL);
	mlx->keys = ft_key_count(mlx->map);
	if (ft_check_path(mlx))
		return (ft_return(mlx), free(mlx), NULL);
	mlx->win = ft_create_win(mlx);
	if (!mlx->win)
		return (ft_return(mlx), free(mlx), NULL);
	mlx->img = ft_get_images(mlx);
	mlx->px = ft_get_coordinates(mlx->map, 'P', 'x');
	mlx->py = ft_get_coordinates(mlx->map, 'P', 'y');
	mlx->collected = 0;
	mlx->steps = 0;
	return (mlx);
}

void	ft_mlx_print_img(t_mlx *mlx, void *img, int x, int y)
{
	char	*steps;

	x *= IMG_SIZE;
	y *= IMG_SIZE;
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, x, y);
	mlx_string_put(mlx->mlx, mlx->win, 5, 12, 0xFF0000, "STEPS : ");
	steps = ft_itoa(mlx->steps);
	mlx_string_put(mlx->mlx, mlx->win, 54, 12, 0xFF0000, steps);
	free(steps);
}

t_img	*ft_get_images(t_mlx *mlx)
{
	t_img	*img;
	int		size;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->door = mlx_xpm_file_to_image(mlx->mlx, DOOR_PATH, &size, &size);
	img->floor = mlx_xpm_file_to_image(mlx->mlx, FLOOR_PATH, &size, &size);
	img->key = mlx_xpm_file_to_image(mlx->mlx, KEY_PATH, &size, &size);
	img->wall = mlx_xpm_file_to_image(mlx->mlx, WALL_PATH, &size, &size);
	img->player_up = mlx_xpm_file_to_image(mlx->mlx, UP, &size, &size);
	img->player_right = mlx_xpm_file_to_image(mlx->mlx, RIGHT, &size, &size);
	img->player_left = mlx_xpm_file_to_image(mlx->mlx, LEFT, &size, &size);
	img->sasuke = mlx_xpm_file_to_image(mlx->mlx, F1, &size, &size);
	return (img);
}
