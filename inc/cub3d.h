/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:08:22 by hunaprk           #+#    #+#             */
/*   Updated: 2023/05/25 18:26:45 by hunpark          ###   ########.fr       */
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
# define X_EVENT_KEY_EXIT	11

# define KEY_ESC 53
# define KEY_A 0
# define KEY_D 2
# define KEY_W 13
# define KEY_S 1

# define mapWidth 24
# define mapHeight 24
# define width 1280
# define height 720
# define MINI_SCALE 1
# define TEX_H 64
# define TEX_W 64
# define PLAYER_SIZE 10


enum direct{
	NO,
	SO,
	WE,
	EA,
};

// typedef struct s_texture
// {
// 	char	*path;
// 	void	*texture;
// 	int		texture_width;
// 	int		texture_height;
// } t_texture;

typedef struct s_cub
{
	char		**map;
	char 		*texture[4];
	int			f_color;
	int			c_color;
	int			map_width;
	int			map_height;
	int			floor;
	int			player;
} t_cub;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
}	t_mlx;


typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_size;
	int		endian;
	int		img_width;
	int		img_height;
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

typedef struct s_tex
{
	int		*tex[4];
	void	*tex_img[4];
	int		**buf;
	int		re_buf;
}	t_tex;

typedef struct s_data
{
	t_player	player;
	t_img		img;
	t_mlx		mlx;
	t_cub		cub;
	t_tex		tex;
	t_ray		ray;
}	t_data;

static int	worldMap[mapWidth][mapHeight] =
						{
							{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
							{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,3},
							{3,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
							{3,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
							{3,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,3},
							{3,0,3,0,0,0,0,1,1,1,1,1,1,1,1,1,2,2,0,2,2,2,2,3},
							{3,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,1,0,0,0,1,1,1,3},
							{3,0,2,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,3},
							{3,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,3},
							{3,0,1,0,0,0,0,3,0,0,0,0,0,0,0,3,1,0,0,0,0,0,0,3},
							{3,0,0,0,0,0,0,3,0,0,0,0,0,0,0,3,1,0,0,0,1,1,1,3},
							{3,0,0,0,0,0,0,3,3,3,3,0,3,3,3,3,1,1,1,1,1,1,1,3},
							{3,2,2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,2,2,2,3},
							{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
							{3,2,2,2,2,2,0,2,2,2,2,0,2,2,2,2,2,2,2,2,2,2,2,3},
							{3,3,3,3,3,3,0,3,3,3,2,0,2,2,2,2,2,2,2,2,3,3,3,3},
							{3,0,0,0,0,0,0,0,0,3,2,0,2,2,0,0,0,0,0,2,0,0,0,3},
							{3,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,3,0,0,2,0,0,0,3},
							{3,0,0,0,0,0,0,0,0,3,2,0,2,2,0,0,0,0,0,2,2,0,2,3},
							{3,0,2,0,2,0,0,0,0,3,2,0,0,0,0,0,3,0,0,0,0,0,0,3},
							{3,0,0,3,0,0,0,0,0,3,2,0,2,2,0,0,0,0,0,2,2,0,2,3},
							{3,0,2,0,2,0,0,0,0,3,2,0,2,2,0,0,3,0,0,2,0,0,0,3},
							{3,0,0,0,0,0,0,0,0,3,2,0,2,2,0,0,0,0,0,2,0,0,0,3},
							{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}
						};

# include "util.h"
# include "parser.h"

// main


// init
void	ft_init(t_data *data, char *av);
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

//init_image
void	ft_init_img(t_data *data);
void	ft_init_buf(t_data *data);
void	ft_init_tex(t_data *data);
void	load_texture(t_data *data);
void	load_image(t_data *data, int *texture, char *path, t_img *img);


void	draw_up_down(t_data *data);
void	next(t_data *data, int x);
void	draw_all(t_data *data);
#endif
