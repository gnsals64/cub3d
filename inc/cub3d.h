/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hupa <hupa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:08:22 by hunaprk           #+#    #+#             */
/*   Updated: 2023/05/22 04:15:47 by hupa             ###   ########.fr       */
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
# define width 1920
# define height 1080
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

typedef struct s_ray
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;
}	t_ray;

typedef struct s_data
{
	t_player	player;
	t_img		img;
	t_mlx		mlx;
	t_cub		cub;
	t_ray		ray;
}	t_data;

static int	worldMap[24][24] = {
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
						};

# include "util.h"
# include "parser.h"

// main


// init
void	ft_init(t_data *data);
void	ft_init_img(t_data *data);
void	ft_init_mlx(t_data *data);
void	ft_init_player(t_data *data);

// utils
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

// hook
int		key_exit(int keycode, t_data *data);
int		key_press(int key, t_data *data);

// loop
int		main_loop(t_data *data);
void	loop(t_data *data);

// init_raycast
void	init_ray(t_data *data, int x);

// raycast
void	raycast(t_data *data);
void	set_raydir(t_data *data, int x);

// dda
void	dda(t_data *data);

// draw
void	verLine(t_data *data, int x, int y1, int y2, int color);
void	draw(t_data *data);

#endif
