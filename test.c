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

int main()
{
	t_info	info;
	t_mlx	mlx;

	ft_init(&info, &mlx);

}
