/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 03:39:55 by hupa              #+#    #+#             */
/*   Updated: 2023/05/25 20:21:20 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		check_raydir(t_data *data)
{
	if(data->ray.side == 1)
	{
		if(data->ray.rayDirY > 0)
			return (SO);
		else
			return (NO);
	}
	else
	{
		if(data->ray.rayDirX > 0)
			return (EA);
		else
			return (WE);
	}
}

void	draw(t_data *data)
{
	data->ray.lineHeight = (int)(height / data->ray.perpWallDist);
	data->ray.drawStart = -data->ray.lineHeight / 2 + height / 2;
	if(data->ray.drawStart < 0)
		data->ray.drawStart = 0;
	data->ray.drawEnd = data->ray.lineHeight / 2 + height / 2;
	if(data->ray.drawEnd >= height)
		data->ray.drawEnd = height - 1;
}

void	verLine(t_data *data, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(data->mlx.mlx_ptr, data->mlx.mlx_win, x, y, color);
		y++;
	}
}
