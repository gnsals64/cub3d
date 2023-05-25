/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:56:12 by junhyupa          #+#    #+#             */
/*   Updated: 2023/05/25 20:56:47 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

enum direct{
	NO,
	SO,
	WE,
	EA,
};

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

#endif