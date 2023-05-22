/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hupa <hupa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 03:39:55 by hupa              #+#    #+#             */
/*   Updated: 2023/05/22 04:12:45 by hupa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw(t_data *data)
{
	data->ray.lineHeight = (int)(height / data->ray.perpWallDist);
	data->ray.drawStart = -data->ray.lineHeight / 2 + height / 2;
	if(data->ray.drawStart < 0)
		data->ray.drawStart = 0;
	data->ray.drawEnd = data->ray.lineHeight / 2 + height / 2;
	if(data->ray.drawEnd >= height)
		data->ray.drawEnd = height - 1;
	if (worldMap[data->ray.mapY][data->ray.mapX] == 1)
		data->ray.color = 0xFF0000;
	else if (worldMap[data->ray.mapY][data->ray.mapX] == 2)
		data->ray.color = 0x00FF00;
	else if (worldMap[data->ray.mapY][data->ray.mapX] == 3)
		data->ray.color = 0x0000FF;
	else if (worldMap[data->ray.mapY][data->ray.mapX] == 4)
		data->ray.color = 0xFFFFFF;
	else
		data->ray.color = 0xFFFF00;
	if (data->ray.side == 1)
		data->ray.color = data->ray.color / 2;
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
