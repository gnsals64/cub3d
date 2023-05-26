/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 03:39:55 by hupa              #+#    #+#             */
/*   Updated: 2023/05/26 13:58:00 by junhyupa         ###   ########.fr       */
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
	data->ray.line_height = (int)(height / data->ray.perp_wall_dist);
	data->ray.draw_start = -data->ray.line_height / 2 + height / 2;
	if(data->ray.draw_start < 0)
		data->ray.draw_start = 0;
	data->ray.draw_end = data->ray.line_height / 2 + height / 2;
	if(data->ray.draw_end >= height)
		data->ray.draw_end = height - 1;
}