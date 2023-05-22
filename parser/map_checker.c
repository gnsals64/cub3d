/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:05:28 by junhyupa          #+#    #+#             */
/*   Updated: 2023/05/22 19:41:33 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	is_elements(char c)
{
	if (!c)
		return (1);
	else if (c == ' ' || c == '1' || c == '\n')
		return (2);
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (3);
	else if (c == '0')
		return (4);
	return (0);
}

static int	is_wall(char **map, t_cub *cub, int x, int y)
{
	if (x < 0 || y < 0 || x >= cub->map_width || y >= cub->map_height)
		return (0);
	if (is_elements(map[y][x]) == 3 || is_elements(map[y][x]) == 4)
		return (1);
	return (0);
}

static int	check_caldinal(char **map, t_cub *cub, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (i <= 1)
	{
		j = -1;
		while (j <= 1)
		{
			if(is_wall(map, cub, x + i , y + j))
				return (1);
			j++;
		}
		i++;
	}
	return(0);
}

void	check_user_direction(int x, int y, t_data *data)
{
	char	c;

	if (data->player.posX >= 0 || data->player.posY >= 0)
		error_control("dup user Error", NULL, 1);
	c = data->cub.map[y][x];
	data->player.posX = x;
	data->player.posY = y;
	if (c == 'N')
		data->player.dirY = 1;
	if (c == 'W')
		data->player.dirX = -1;
	if (c == 'S')
		data->player.dirY = -1;
	if (c == 'E')
		data->player.dirX = 1;
}

void	map_checker(char **map, t_cub *cub, t_data *data)
{
	int	x;
	int	y;

	(void)data;
	x = 0;
	y = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x] && map[y][x] != '\n')
		{
			if (is_elements(map[y][x]) == 0)
				error_control("map elements Error", NULL, 1);
			if ((y == 0 || y == cub->map_height || x == 0) && \
				(map[y][x] != ' ' && map[y][x] != '1'))
				error_control("map Error", NULL, 1);
			if (map[y][x] == ' ' && check_caldinal(map, cub, x, y))
				error_control("map Error2", NULL, 1);
			// if (is_elements(map[y][x]) == 3)
			// 	check_user_direction(x, y, data);
			x++;
		}
		if(map[y][x - 1] != ' ' && map[y][x - 1] != '1')
			error_control("map Error3", NULL, 1);
		y++;
	}
}
