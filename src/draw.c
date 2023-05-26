/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 03:39:55 by hupa              #+#    #+#             */
/*   Updated: 2023/05/26 14:06:42 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		check_raydir(t_data *data)
{
	if(data->ray.side == 1)
	{
		if(data->ray.raydir_y > 0)
			return (SO);
		else
			return (NO);
	}
	else
	{
		if(data->ray.raydir_x > 0)
			return (EA);
		else
			return (WE);
	}
}

void	draw(t_data *data)
{
	data->ray.line_height = (int)(HEIGHT / data->ray.perp_wall_dist);
	data->ray.draw_start = -data->ray.line_height / 2 + HEIGHT / 2;
	if(data->ray.draw_start < 0)
		data->ray.draw_start = 0;
	data->ray.draw_end = data->ray.line_height / 2 + HEIGHT / 2;
	if(data->ray.draw_end >= HEIGHT)
		data->ray.draw_end = HEIGHT - 1;
}
