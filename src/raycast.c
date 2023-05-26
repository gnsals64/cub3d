/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 03:14:50 by hupa              #+#    #+#             */
/*   Updated: 2023/05/26 15:19:59 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	raycast(t_data *data)
{
	int	x;

	x = 0;
	// for (int i = 0; i < HEIGHT; i++)
	// {
	// 	for (int j = 0; j < WIDTH; j++)
	// 	{
	// 		if (i > HEIGHT / 2)
	// 			data->tex.buf[i][j] = data->cub.f_color;
	// 		else
	// 			data->tex.buf[i][j] = data->cub.c_color;
	// 	}
	// }
	draw_ceiling_floor(data);
	while (x < WIDTH)
	{
		init_ray(data, x);
		dda(data);
		draw(data);
		next(data, x);
		x++;
	}
}

void	next(t_data *data, int x)
{
	int texNum = check_raydir(data);

	double wallX;
	if (data->ray.side == 0)
		wallX = -(data->player.pos_y + data->ray.perp_wall_dist * data->ray.raydir_y);
	else
		wallX = -(data->player.pos_x + data->ray.perp_wall_dist * data->ray.raydir_x);
	wallX -= floor(wallX);
	int texX = (int)(wallX * (double)TEX_W);
	if (data->ray.side == 0 && data->ray.raydir_x > 0)
		texX = TEX_W - texX - 1;
	if (data->ray.side == 1 && data->ray.raydir_y < 0)
		texX = TEX_W - texX - 1;
	double step = 1.0 * TEX_H / data->ray.line_height;
	double texPos = (data->ray.draw_start - HEIGHT / 2 + data->ray.line_height / 2) * step;
	for (int y = data->ray.draw_start; y < data->ray.draw_end; y++)
	{
		int texY = (int)texPos & (TEX_H - 1);
		texPos += step;
		int color = data->tex.tex[texNum][TEX_H * texY + texX];
		if (data->ray.side == 1)
			color = (color >> 1) & 8355711;
		data->tex.buf[y][x] = color;
		data->tex.re_buf = 1;
	}
}

// void	draw_all(t_data *data)
// {
// 	for (int y = 0; y < HEIGHT; y++)
// 	{
// 		for (int x = 0; x < WIDTH; x++)
// 		{
// 			data->img.addr[y * WIDTH + x] = data->tex.buf[y][x];
// 		}
// 	}
// 	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win, data->img.img, 0, 0);
// }
