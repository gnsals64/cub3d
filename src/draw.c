/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 03:39:55 by hupa              #+#    #+#             */
/*   Updated: 2023/05/26 14:58:50 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		check_raydir(t_data *data)
{
	if(data->ray.side == 1)
	{
		if(data->ray.raydir_y > 0)
			return (NO);
		else
			return (SO);
	}
	else
	{
		if(data->ray.raydir_x > 0)
			return (WE);
		else
			return (EA);
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
