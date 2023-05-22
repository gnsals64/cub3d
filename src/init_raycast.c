/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 03:29:22 by hupa              #+#    #+#             */
/*   Updated: 2023/05/22 19:40:56 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	set_raydir(t_data *data, int x)
{
	(void)x;
	if (data->ray.rayDirX < 0)
	{
		data->ray.stepX = -1;
		data->ray.sideDistX = (data->player.posX - data->ray.mapX) * data->ray.deltaDistX;
	}
	else
	{
		data->ray.stepX = 1;
		data->ray.sideDistX = (data->ray.mapX + 1.0 - data->player.posX) * data->ray.deltaDistX;
	}
	if (data->ray.rayDirY < 0)
	{
		data->ray.stepY = -1;
		data->ray.sideDistY = (data->player.posY - data->ray.mapY) * data->ray.deltaDistY;
	}
	else
	{
		data->ray.stepY = 1;
		data->ray.sideDistY = (data->ray.mapY + 1.0 - data->player.posY) * data->ray.deltaDistY;
	}
}

void	init_ray(t_data *data, int x)
{
	data->ray.cameraX = 2 * x / (double)width - 1;
	data->ray.rayDirX = data->player.dirX + data->player.planeX * data->ray.cameraX;
	data->ray.rayDirY = data->player.dirY + data->player.planeY * data->ray.cameraX;
	data->ray.mapX = (int)data->player.posX;
	data->ray.mapY = (int)data->player.posY;
	data->ray.deltaDistX = fabs(1 / data->ray.rayDirX);
	data->ray.deltaDistY = fabs(1 / data->ray.rayDirY);
	data->ray.hit = 0;
	set_raydir(data, x);
}
