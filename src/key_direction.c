/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:30:56 by junhyupa          #+#    #+#             */
/*   Updated: 2023/05/26 15:48:42 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	keypress_w(t_data *data)
{
	if (data->cub.map[(int)(data->player.pos_y)][(int)(data->player.pos_x \
	+ (data->player.dir_x * (data->player.move_speed + 0.15)))] != '1')
		data->player.pos_x += data->player.dir_x * data->player.move_speed;
	if (data->cub.map[(int)(data->player.pos_y + (data->player.dir_y \
	* (data->player.move_speed + 0.15)))][(int)(data->player.pos_x)] != '1')
		data->player.pos_y += data->player.dir_y * data->player.move_speed;
}

void	keypress_a(t_data *data)
{		
	if (data->cub.map[(int)(data->player.pos_y)][(int)(data->player.pos_x \
	- (data->player.plane_x * (data->player.move_speed + 0.15)))] != '1')
		data->player.pos_x -= data->player.plane_x * data->player.move_speed;
	if (data->cub.map[(int)(data->player.pos_y - (data->player.plane_y \
	* (data->player.move_speed + 0.15)))][(int)(data->player.pos_x)] != '1')
		data->player.pos_y -= data->player.plane_y * data->player.move_speed;
}

void	keypress_s(t_data *data)
{
	if (data->cub.map[(int)(data->player.pos_y)][(int)(data->player.pos_x \
	- (data->player.dir_x * (data->player.move_speed + 0.15)))] != '1')
		data->player.pos_x -= data->player.dir_x * data->player.move_speed;
	if (data->cub.map[(int)(data->player.pos_y - (data->player.dir_y \
	* (data->player.move_speed + 0.15)))][(int)(data->player.pos_x)] != '1')
		data->player.pos_y -= data->player.dir_y * data->player.move_speed;
}

void	keypress_d(t_data *data)
{
	if (data->cub.map[(int)(data->player.pos_y)][(int)(data->player.pos_x \
	+ (data->player.plane_x * (data->player.move_speed + 0.15)))] != '1')
		data->player.pos_x += data->player.plane_x * data->player.move_speed;
	if (data->cub.map[(int)(data->player.pos_y + (data->player.plane_y \
	* (data->player.move_speed + 0.15)))][(int)(data->player.pos_x)] != '1')
		data->player.pos_y += data->player.plane_y * data->player.move_speed;
}
