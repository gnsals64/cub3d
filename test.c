#include <cub3d.h>

void	ft_init(t_info *info, t_mlx *mlx)
{
	info->posX = 22;
	info->posY = 12;
	info->dirX = -1;
	info->dirY = 0;
	info->planeX = 0;
	info->planeY = 0.66;
	info->moveSpeed = 0.05;
	info->rotSpeed = 0.05;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");

}

void fill_squares(t_img *map, int x, int y, int color)
{
	int i;
	int j;

	j = 0;
	while (j < (int)(MINI_SCALE * TILE_SIZE))
	{
		i = 0;
		while (i < (int)(MINI_SCALE * TILE_SIZE))
		{
			map->data[(int)(MINI_SCALE * WINDOW_WIDTH) * (y + j) + (x + i)] = color;
			i++;
		}
		j++;
	}
}

void	render_map(t_mlx *mlx, t_img *map)
{
	map->data = (int *)mlx_get_data_addr(map->img, &(map->bpp), &(map->line_size), &(map->endian));
	int col;
	int row;

	row = 0;
	while (row < MAP_NUM_ROWS)
	{
		col = 0;
		while (col < MAP_NUM_COLS)
		{
			if (mini_map[row][col] == 1)
				fill_squares(map, (int)(MINI_SCALE * TILE_SIZE * col), (int)(MINI_SCALE * TILE_SIZE * row), 0x000000);
			else
				fill_squares(map, (int)(MINI_SCALE * TILE_SIZE * col), (int)(MINI_SCALE * TILE_SIZE * row), 0xffffff);
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, map->img, (int)(WINDOW_WIDTH * (1 - MINI_SCALE)), (int)(WINDOW_HEIGHT * (1 - MINI_SCALE)));
}

int main()
{
	t_info	info;
	t_mlx	mlx;
	t_img	img;

	ft_init(&info, &mlx);
	img.img = mlx_new_image(mlx.mlx, (int)MINI_SCALE * WINDOW_WIDTH, (int)MINI_SCALE * WINDOW_HEIGHT);
	render_map(&mlx, &img);
	mlx_loop(&mlx);
}
