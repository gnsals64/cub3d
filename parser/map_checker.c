/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:05:28 by junhyupa          #+#    #+#             */
/*   Updated: 2023/05/17 16:38:46 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	is_wall(char **map, t_cub *cub, int x, int y)
{
	if (x < 0 || y < 0 || x >= cub->map_width || y >= cub->map_height)
		return (0);
	if (map[y][x] && map[y][x] != ' ' && map[y][x] != '1' && map[y][x] != '\n')
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

static void	check_surround(char **map, t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x] && map[y][x] != '\n')
		{
			if ((y == 0 || y == cub->map_height || x == 0 || x == cub->map_width) && \
				(map[y][x] != ' ' && map[y][x] != '1'))
				error_control("map Error", NULL, 1);
			if (map[y][x] == ' ' && check_caldinal(map, cub, x, y))
			{
				printf("%d %d", x, y);
				error_control("map Error2", NULL, 1);
			}
			x++;
		}
		if(map[y][x - 1] != ' ' && map[y][x - 1] != '1' && map[y][x - 1] != '\n')
			error_control("map Error3", NULL, 1);
		y++;
	}
}

void	map_checker(t_cub *cub)
{
	check_surround(cub->map, cub);
}