/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:27:39 by hupa              #+#    #+#             */
/*   Updated: 2023/05/26 15:00:55 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	key_exit(t_data *data)
{	
	free_all(data);
	exit (0);
}

int	key_press(int key, t_data *data)
{
	if (key == KEY_W)
	{
		if (data->cub.map[(int)(data->player.pos_y)][(int)(data->player.pos_x + (data->player.dir_x * (data->player.move_speed + 0.15)))] != '1')
			data->player.pos_x += data->player.dir_x * data->player.move_speed;
		printf("%c\n",data->cub.map[(int)(data->player.pos_y + (data->player.dir_y * data->player.move_speed + 0.15))][(int)(data->player.pos_x)]);
		if (data->cub.map[(int)(data->player.pos_y + (data->player.dir_y * (data->player.move_speed + 0.15)))][(int)(data->player.pos_x)] != '1')
			data->player.pos_y += data->player.dir_y * data->player.move_speed;
		printf("x : %f y:%f\n", data->player.pos_x, data->player.pos_y);
	}
	if (key == KEY_S)
	{
		if (data->cub.map[(int)(data->player.pos_y)][(int)(data->player.pos_x - (data->player.dir_x * (data->player.move_speed + 0.15)))] != '1')
			data->player.pos_x -= data->player.dir_x * data->player.move_speed;
		if (data->cub.map[(int)(data->player.pos_y - (data->player.dir_y * (data->player.move_speed + 0.15)))][(int)(data->player.pos_x)] != '1')
			data->player.pos_y -= data->player.dir_y * data->player.move_speed;
		printf("x : %f y:%f\n", data->player.pos_x, data->player.pos_y);
	}
	if (key == KEY_RIGHT)
	{
		double olddir_x = data->player.dir_x;
		data->player.dir_x = data->player.dir_x * cos(data->player.rot_speed) - data->player.dir_y * sin(data->player.rot_speed);
		data->player.dir_y = olddir_x * sin(data->player.rot_speed) + data->player.dir_y * cos(data->player.rot_speed);
		double oldplane_x = data->player.plane_x;
		data->player.plane_x = data->player.plane_x * cos(data->player.rot_speed) - data->player.plane_y * sin(data->player.rot_speed);
		data->player.plane_y = oldplane_x * sin(data->player.rot_speed) + data->player.plane_y * cos(data->player.rot_speed);
	}
	if (key == KEY_LEFT)
	{
		double olddir_x = data->player.dir_x;
		data->player.dir_x = data->player.dir_x * cos(-data->player.rot_speed) - data->player.dir_y * sin(-data->player.rot_speed);
		data->player.dir_y = olddir_x * sin(-data->player.rot_speed) + data->player.dir_y * cos(-data->player.rot_speed);
		double oldplane_x = data->player.plane_x;
		data->player.plane_x = data->player.plane_x * cos(-data->player.rot_speed) - data->player.plane_y * sin(-data->player.rot_speed);
		data->player.plane_y = oldplane_x * sin(-data->player.rot_speed) + data->player.plane_y * cos(-data->player.rot_speed);
	}
	if (key == KEY_ESC)
		key_exit(data);
	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.mlx_win);
	main_loop(data);
	return (0);
}
