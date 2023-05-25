/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 03:08:15 by hupa              #+#    #+#             */
/*   Updated: 2023/05/25 15:36:57 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main_loop(t_data *data)
{
	raycast(data);
	draw_all(data);
	return (0);
}

void	loop(t_data *data)
{
	//draw_up_down(data);
	mlx_loop_hook(data->mlx.mlx_ptr, &main_loop, data);
	mlx_hook(data->mlx.mlx_win, X_EVENT_KEY_PRESS, 1L<<0, &key_press, data);
	//mlx_hook(data->mlx.mlx_win, X_EVENT_KEY_EXIT, 1L<<0, &key_exit, data);
	mlx_loop(data->mlx.mlx_ptr);
}