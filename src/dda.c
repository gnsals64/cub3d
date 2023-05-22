/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hupa <hupa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 03:42:24 by hupa              #+#    #+#             */
/*   Updated: 2023/05/22 04:10:21 by hupa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	dda(t_data *data)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.sideDistX < data->ray.sideDistY)
		{
			data->ray.sideDistX += data->ray.deltaDistX;
			data->ray.mapX += data->ray.stepX;
			data->ray.side = 0;
		}
		else
		{
			data->ray.sideDistY += data->ray.deltaDistY;
			data->ray.mapY += data->ray.stepY;
			data->ray.side = 1;
		}
		if (worldMap[data->ray.mapX][data->ray.mapY] > 0)
			data->ray.hit = 1;
	}
	if (data->ray.side == 0)
		data->ray.perpWallDist = (data->ray.mapX - data->player.posX + (1 - data->ray.stepX) / 2) / data->ray.rayDirX;
	else
		data->ray.perpWallDist = (data->ray.mapY - data->player.posY + (1 - data->ray.stepY) / 2) / data->ray.rayDirY;
}
