/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:40:46 by hupa              #+#    #+#             */
/*   Updated: 2023/05/17 17:48:58 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_init_mlx(t_data *data)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, width, height, "cub3d");
	data->mlx = mlx;
}

void	ft_init_img(t_data *data)
{
	t_img	img;

	img.img = mlx_new_image(data->mlx.mlx_ptr, (int)(MINI_SCALE * WINDOW_WIDTH), (int)(MINI_SCALE * WINDOW_HEIGHT));
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_size, &img.endian);
	data->img = img;
}

void	ft_init_player(t_data *data)
{
	t_player	player;

	player.posX = -1;
	player.posY = -1;
	player.dirX = 0;
	player.dirY = 0;
	player.planeX = 0;
	player.planeY = 0.66;
	player.moveSpeed = 0.05;
	player.rotSpeed = 0.05;
	player.player_size = PLAYER_SIZE;
	data->player = player;
}

void	ft_init_cub(t_data *data)
{
	t_cub	cub;
	int		i;

	i = 0;
	cub.map = NULL;
	while (i < 4)
	{
		cub.texture[i].path = NULL;
		cub.texture[i].texture = NULL;
		cub.texture->texture_width = 0;
		cub.texture->texture_height = 0;
		i++;
	}
	cub.f_color = 0;
	cub.c_color = 0;
	cub.map_width = 0;
	cub.map_height = 0;
	data->cub = cub;
}

void	ft_init(t_data *data)
{
	ft_init_mlx(data);
	ft_init_img(data);
	ft_init_player(data);
	ft_init_cub(data);
}
