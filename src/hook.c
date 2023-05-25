/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:27:39 by hupa              #+#    #+#             */
/*   Updated: 2023/05/25 19:55:09 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	key_exit(int keycode, t_data *data)
{
	(void)keycode;
	(void)data;
	exit(0);
}

int	key_press(int key, t_data *data)
{
	if (key == KEY_W)
	{
		if (data->cub.map[(int)(data->player.posY)][(int)(data->player.posX + (data->player.dirX * (data->player.moveSpeed + 0.15)))] != '1')
			data->player.posX += data->player.dirX * data->player.moveSpeed;
		printf("%c\n",data->cub.map[(int)(data->player.posY + (data->player.dirY * data->player.moveSpeed + 0.15))][(int)(data->player.posX)]);
		if (data->cub.map[(int)(data->player.posY + (data->player.dirY * (data->player.moveSpeed + 0.15)))][(int)(data->player.posX)] != '1')
			data->player.posY += data->player.dirY * data->player.moveSpeed;
		printf("x : %f y:%f\n", data->player.posX, data->player.posY);
	}
	if (key == KEY_S)
	{
		if (data->cub.map[(int)(data->player.posY)][(int)(data->player.posX - (data->player.dirX * (data->player.moveSpeed + 0.15)))] != '1')
			data->player.posX -= data->player.dirX * data->player.moveSpeed;
		if (data->cub.map[(int)(data->player.posY - (data->player.dirY * (data->player.moveSpeed + 0.15)))][(int)(data->player.posX)] != '1')
			data->player.posY -= data->player.dirY * data->player.moveSpeed;
		printf("x : %f y:%f\n", data->player.posX, data->player.posY);
	}
	if (key == KEY_D)
	{
		double oldDirX = data->player.dirX;
		data->player.dirX = data->player.dirX * cos(data->player.rotSpeed) - data->player.dirY * sin(data->player.rotSpeed);
		data->player.dirY = oldDirX * sin(data->player.rotSpeed) + data->player.dirY * cos(data->player.rotSpeed);
		double oldPlaneX = data->player.planeX;
		data->player.planeX = data->player.planeX * cos(data->player.rotSpeed) - data->player.planeY * sin(data->player.rotSpeed);
		data->player.planeY = oldPlaneX * sin(data->player.rotSpeed) + data->player.planeY * cos(data->player.rotSpeed);
	}
	if (key == KEY_A)
	{
		double oldDirX = data->player.dirX;
		data->player.dirX = data->player.dirX * cos(-data->player.rotSpeed) - data->player.dirY * sin(-data->player.rotSpeed);
		data->player.dirY = oldDirX * sin(-data->player.rotSpeed) + data->player.dirY * cos(-data->player.rotSpeed);
		double oldPlaneX = data->player.planeX;
		data->player.planeX = data->player.planeX * cos(-data->player.rotSpeed) - data->player.planeY * sin(-data->player.rotSpeed);
		data->player.planeY = oldPlaneX * sin(-data->player.rotSpeed) + data->player.planeY * cos(-data->player.rotSpeed);
	}
	if (key == KEY_ESC)
		exit(0);
	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.mlx_win);
	main_loop(data);
	return (0);
}
