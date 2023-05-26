/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 03:14:50 by hupa              #+#    #+#             */
/*   Updated: 2023/05/26 15:54:57 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	raycast(t_data *data)
{
	int	x;

	x = 0;
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
