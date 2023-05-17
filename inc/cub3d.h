/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:08:22 by hunaprk           #+#    #+#             */
/*   Updated: 2023/05/17 16:24:26 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../GNL/get_next_line.h"
# include <mlx.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <err.h>
# include <errno.h>
# include <fcntl.h>

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_release	3
# define X_EVENT_KEY_EXIT	17

# define KEY_ESC 65307
# define KEY_A 97
# define KEY_D 100
# define KEY_W 119
# define KEY_S 115

# define mapWidth 24
# define mapHeight 24
# define width 640
# define height 480
# define MINI_SCALE 1
# define TILE_SIZE 80
# define MAP_NUM_ROWS 12
# define MAP_NUM_COLS 20
# define PLAYER_SIZE 10

# define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
# define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

enum direct{
	NO,
	SO,
	WE,
	EA,
};

typedef struct s_texture
{
	char	*path;
	void	*texture;
	int		texture_width;
	int		texture_height;
} t_texture;

typedef struct s_cub
{
	char		**map;
	t_texture	texture[4];
	int			f_color;
	int			c_color;
	int			map_width;
	int			map_height;
} t_cub;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
}	t_mlx;


typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_size;
	int		endian;
}	t_img;

typedef struct s_player
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	moveSpeed;
	double	rotSpeed;
	int		player_size;
	int		texture[8][TILE_SIZE * TILE_SIZE];
}	t_player;

typedef struct s_data
{
	t_player	player;
	t_img		img;
	t_mlx		mlx;
	t_cub		cub;
}	t_data;

static int map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1},
	{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

# include "util.h"
# include "parser.h"

// main
void	hook(t_data *data);

// init
void	ft_init(t_data *data);
void	ft_init_img(t_data *data);
void	ft_init_mlx(t_data *data);
void	ft_init_player(t_data *data);

// render
void	fill_squares(t_img *img, int x, int y, int color);
void	draw_map(t_mlx *mlx, t_img *img);
void	render(t_data *data);
void	draw_player(t_mlx *mlx, t_player *player, t_img *img);

// utils
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

// hook
int		key_move(int keycode, t_data *data);
int		key_exit(int keycode, t_data *data);

#endif
