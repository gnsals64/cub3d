/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:18:03 by yohlee            #+#    #+#             */
/*   Updated: 2023/05/26 13:59:23 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24
#define width 1280
#define height 720
# define KEY_ESC 53
# define KEY_A 0
# define KEY_D 2
# define KEY_W 13
# define KEY_S 1

typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct	s_info
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double plane_y;
	void	*mlx;
	void	*win;
	t_img	img;
	int		buf[height][width];
	int		**texture;
	double	move_speed;
	double	rot_speed;
	int		re_buf;

}				t_info;

int	worldMap[mapWidth][mapHeight] =
						{
							{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
							{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
							{4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
							{4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
							{4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
							{4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
							{4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
							{4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
							{4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
							{4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
							{4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
							{4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
							{6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
							{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
							{6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
							{4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
							{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
							{4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
							{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
							{4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
							{4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
							{4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
							{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
							{4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
						};

void	draw(t_info *info)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			info->img.data[y * width + x] = info->buf[y][x];
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	calc(t_info *info)
{
	int	x;

	x = 0;
	if (info->re_buf == 1)
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				info->buf[i][j] = 0;
			}
		}
	}
	while (x < width)
	{
		double camera_x = 2 * x / (double)width - 1;
		double rayDirX = info->dirX + info->planeX * camera_x;
		double rayDirY = info->dirY + info->plane_y * camera_x;

		int map_x = (int)info->posX;
		int map_y = (int)info->posY;

		//length of ray from current position to next x or y-side
		double side_dist_x;
		double side_dist_y;

		 //length of ray from one x or y-side to next x or y-side
		double delta_dist_x = fabs(1 / rayDirX);
		double delta_dist_y = fabs(1 / rayDirY);
		double perp_wall_dist;

		//what direction to step in x or y-direction (either +1 or -1)
		int step_x;
		int step_y;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		if (rayDirX < 0)
		{
			step_x = -1;
			side_dist_x = (info->posX - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - info->posX) * delta_dist_x;
		}
		if (rayDirY < 0)
		{
			step_y = -1;
			side_dist_y = (info->posY - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - info->posY) * delta_dist_y;
		}

		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			//Check if ray has hit a wall
			if (worldMap[map_x][map_y] > 0) hit = 1;
		}
		if (side == 0)
			perp_wall_dist = (map_x - info->posX + (1 - step_x) / 2) / rayDirX;
		else
			perp_wall_dist = (map_y - info->posY + (1 - step_y) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int line_height = (int)(height / perp_wall_dist);

		//calculate lowest and highest pixel to fill in current stripe
		int draw_start = -line_height / 2 + height / 2;
		if(draw_start < 0)
			draw_start = 0;
		int draw_end = line_height / 2 + height / 2;
		if(draw_end >= height)
			draw_end = height - 1;

		// texturing calculations
		int texNum = worldMap[map_x][map_y];

		// calculate value of wallX
		double wallX;
		if (side == 0)
			wallX = info->posY + perp_wall_dist * rayDirY;
		else
			wallX = info->posX + perp_wall_dist * rayDirX;
		wallX -= floor(wallX);

		// x coordinate on the texture
		int texX = (int)(wallX * (double)texWidth);
		if (side == 0 && rayDirX > 0)
			texX = texWidth - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = texWidth - texX - 1;

		// How much to increase the texture coordinate perscreen pixel
		double step = 1.0 * texHeight / line_height;
		// Starting texture coordinate
		double texPos = (draw_start - height / 2 + line_height / 2) * step;
		for (int y = draw_start; y < draw_end; y++)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int)texPos & (texHeight - 1);
			texPos += step;
			int color = info->texture[texNum][texHeight * texY + texX];
			// make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			if (side == 1)
				color = (color >> 1) & 8355711;
			info->buf[y][x] = color;
			info->re_buf = 1;
		}
		x++;
	}
}

int	main_loop(t_info *info)
{
	calc(info);
	draw(info);
	return (0);
}

int	key_press(int key, t_info *info)
{
	if (key == KEY_W)
	{
		if (!worldMap[(int)(info->posX + info->dirX * info->move_speed)][(int)(info->posY)])
			info->posX += info->dirX * info->move_speed;
		if (!worldMap[(int)(info->posX)][(int)(info->posY + info->dirY * info->move_speed)])
			info->posY += info->dirY * info->move_speed;
	}
	//move backwards if no wall behind you
	if (key == KEY_S)
	{
		if (!worldMap[(int)(info->posX - info->dirX * info->move_speed)][(int)(info->posY)])
			info->posX -= info->dirX * info->move_speed;
		if (!worldMap[(int)(info->posX)][(int)(info->posY - info->dirY * info->move_speed)])
			info->posY -= info->dirY * info->move_speed;
	}
	//rotate to the right
	if (key == KEY_D)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rot_speed) - info->dirY * sin(-info->rot_speed);
		info->dirY = oldDirX * sin(-info->rot_speed) + info->dirY * cos(-info->rot_speed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(-info->rot_speed) - info->plane_y * sin(-info->rot_speed);
		info->plane_y = oldPlaneX * sin(-info->rot_speed) + info->plane_y * cos(-info->rot_speed);
	}
	//rotate to the left
	if (key == KEY_A)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rot_speed) - info->dirY * sin(info->rot_speed);
		info->dirY = oldDirX * sin(info->rot_speed) + info->dirY * cos(info->rot_speed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rot_speed) - info->plane_y * sin(info->rot_speed);
		info->plane_y = oldPlaneX * sin(info->rot_speed) + info->plane_y * cos(info->rot_speed);
	}
	if (key == KEY_ESC)
		exit(0);
	mlx_clear_window(info->mlx, info->win);
	main_loop(info);
	return (0);
}

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	for (int y = 0; y < img->img_height; y++)
	{
		for (int x = 0; x < img->img_width; x++)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->texture[0], "tex/textures/east.xpm", &img);
	load_image(info, info->texture[1], "tex/textures/west.xpm", &img);
	load_image(info, info->texture[2], "tex/textures/purplestone.xpm", &img);
	load_image(info, info->texture[3], "tex/textures/east.xpm", &img);
	load_image(info, info->texture[4], "tex/textures/bluestone.xpm", &img);
	load_image(info, info->texture[5], "tex/textures/mossy.xpm", &img);
	load_image(info, info->texture[6], "tex/textures/west.xpm", &img);
	load_image(info, info->texture[7], "tex/textures/colorstone.xpm", &img);
}

int	main(void)
{
	t_info info;
	info.mlx = mlx_init();

	info.posX = 22.0;
	info.posY = 11.5;
	info.dirX = -1.0;
	info.dirY = 0.0;
	info.planeX = 0.0;
	info.plane_y = 0.66;
	info.re_buf = 0;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			info.buf[i][j] = 0;
		}
	}

	if (!(info.texture = (int **)malloc(sizeof(int *) * 8)))
		return (-1);
	for (int i = 0; i < 8; i++)
	{
		if (!(info.texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth))))
			return (-1);
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < texHeight * texWidth; j++)
		{
			info.texture[i][j] = 0;
		}
	}

	load_texture(&info);

	info.move_speed = 0.05;
	info.rot_speed = 0.05;

	info.win = mlx_new_window(info.mlx, width, height, "mlx");

	info.img.img = mlx_new_image(info.mlx, width, height);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);

	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 1L<<0, &key_press, &info);

	mlx_loop(info.mlx);
}
