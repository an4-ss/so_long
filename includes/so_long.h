/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:56:56 by anass             #+#    #+#             */
/*   Updated: 2025/03/30 15:39:04 by anass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MAX_COL 100
# define IMG_SIZE 64

# define WALL_PATH "./textures/map/wall.xpm"
# define FLOOR_PATH "./textures/map/floor.xpm"
# define KEY_PATH "./textures/map/key.xpm"
# define DOOR_PATH "./textures/map/door.xpm"
# define UP	"./textures/player/up.xpm"
# define DOWN "./textures/player/down.xpm"
# define RIGHT "./textures/player/right.xpm"
# define LEFT "./textures/player/left.xpm"

# define ESC_KEY 65307
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100 

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "mlx.h"
# include "get_next_line.h"

typedef struct s_img
{
	void	*player_right;
	void	*player_left;
	void	*player_up;
	void	*player_down;
	void	*floor;
	void	*wall;
	void	*door;
	void	*key;
}t_img;

typedef struct s_mlx
{
	int		fd;
	void	*mlx;
	void	*win;
	char	**map;
	t_img	*img;
	int		px;
	int		py;
	int		keys;
	int		collected;
	int		steps;
}t_mlx;

t_mlx	*ft_mlx_init(char *str);
char	**ft_get_map(int fd);
int		ft_input(int keycode, t_mlx *mlx);
void	ft_map_gen(t_mlx *mlx);
void	ft_mlx_print_img(t_mlx *mlx, void *img, int x, int y);
int		ft_exit(t_mlx *mlx);
int		ft_get_coordinates(char **map, int obg, int axis);
int		ft_get_win_size(char **map, int axis);
char	*ft_itoa(int n);
int		ft_key_count(char **map);
void	ft_win(t_mlx *mlx);
void	ft_free_map(char **map);
t_img	*ft_get_images(t_mlx *mlx);
char	**ft_check_map(char **map);
int		ft_strlen(char *str);
char	*ft_strdup(char *s);
int		ft_check_extension(char *path);
int		ft_check_path(t_mlx *mlx);
void	ft_error_msg(unsigned int msg);

#endif