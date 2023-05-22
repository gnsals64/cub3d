/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hupa <hupa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 03:14:50 by hupa              #+#    #+#             */
/*   Updated: 2023/05/22 04:13:28 by hupa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	raycast(t_data *data)
{
	int	x;

	x = 0;
	while (x < width)
	{
		init_ray(data, x);
		dda(data);
		draw(data);
		verLine(data, x, data->ray.drawStart, data->ray.drawEnd, data->ray.color);
		x++;
	}
}
