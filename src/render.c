/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hupa <hupa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:41:46 by hupa              #+#    #+#             */
/*   Updated: 2023/05/16 22:33:54 by hupa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	fill_squares(t_img *img, int x, int y, int color)
{
	int i;
	int j;

	j = 0;
	while (j < (int)(MINI_SCALE * TILE_SIZE) - 1)
	{
		i = 0;
		while (i < (int)(MINI_SCALE * TILE_SIZE) - 1)
		{
			my_mlx_pixel_put(img, x + i, y + j, color);
			i++;
		}
		my_mlx_pixel_put(img, x + i, y + j, 0x000000);
		j++;
	}
	i = 0;
	while (i < (int)(MINI_SCALE * TILE_SIZE))
	{
		my_mlx_pixel_put(img, x + i, y + j, 0x000000);
		i++;
	}
}

void	draw_map(t_mlx *mlx, t_img *img)
{
	int col;
	int row;

	row = 0;
	while (row < MAP_NUM_ROWS)
	{
		col = 0;
		while (col < MAP_NUM_COLS)
		{
			if (map[row][col] == 1)
				fill_squares(img, (int)(MINI_SCALE * TILE_SIZE * col), (int)(MINI_SCALE * TILE_SIZE * row), 0x000000);
			else
				fill_squares(img, (int)(MINI_SCALE * TILE_SIZE * col), (int)(MINI_SCALE * TILE_SIZE * row), 0xffffff);
			col++;
		}
		row++;
	}
}

void	draw_player(t_mlx *mlx, t_player *player, t_img *img)
{
	int	row;
	int	col;

	row = -(player->player_size) / 2;
	while (row < (player->player_size) / 2)
	{
		col = -(player->player_size) / 2;
		while (col < (player->player_size) / 2)
		{
			my_mlx_pixel_put(img, col + player->posX, row + player->posY, 0x0000FF);
			col++;
		}
		row++;
	}
}

void	render(t_data *data)
{
	draw_map(&data->mlx, &data->img);
	draw_player(&data->mlx, &data->player, &data->img);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win, data->img.img, 0, 0);
}
