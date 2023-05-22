/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:15:28 by junhyupa          #+#    #+#             */
/*   Updated: 2023/05/22 19:37:54 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_up_down(t_data *data)
{
	int	x;
	int	y;
	
	y = 0;
	while(y < height)
	{
		x = 0;
		while (x < width)
		{
			if (y <= height / 2)
				mlx_pixel_put(data->mlx.mlx_ptr, data->mlx.mlx_win , x, y, data->cub.c_color);
			else
				mlx_pixel_put(data->mlx.mlx_ptr, data->mlx.mlx_win , x, y, data->cub.f_color);
			x++;
		}
		y++;
	}
}