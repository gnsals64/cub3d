/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hupa <hupa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:27:39 by hupa              #+#    #+#             */
/*   Updated: 2023/05/16 22:33:34 by hupa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	key_move(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_A)
		data->player.posX -= data->player.moveSpeed;
	if (keycode == KEY_D)
		data->player.posX += data->player.moveSpeed;
	if (keycode == KEY_S)
		data->player.posY += data->player.moveSpeed;
	if (keycode == KEY_W)
		data->player.posY -= data->player.moveSpeed;
	render(data);
	return (0);
}

int	key_exit(int keycode, t_data *data)
{
	exit(0);
}
