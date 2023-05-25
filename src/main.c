/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hupa <hupa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:40:17 by hupa              #+#    #+#             */
/*   Updated: 2023/05/25 13:41:00 by hupa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	print_box(char **box)
{
	int	i;

	i = 0;
	while (box[i])
		ft_putstr_fd(box[i++], 1);
}

// void	print_info(t_cub *info)
// {
// 	printf("no : %s \nso : %s \nwe : %s \nea : %s \nmap_width : %d map_height : %d\n", data->player.texture[NO].path, data->player.texture[SO].path, data->player.texture[WE].path, data->player.texture[EA].path, data->player.map_width, data->player.map_height);
// 	printf("fc : %d, %d, %d, cc : %d, %d, %d\n",  data->player. f_color >> 16 & 255, data->player.f_color >> 8 & 255, data->player.f_color & 255, data->player. c_color >> 16 & 255, data->player.c_color >> 8 & 255, data->player.c_color & 255);
// 	print_box(data->player.map);
// 	write(1,"\n",1);
// }

static int	is_cub(char *av)
{
	size_t	len;

	len = ft_strlen(av);
	if (len < 5)
		error_control(".cub file only Error", NULL, 1);
	if (ft_strncmp(".cub", &av[len - 4], 4))
		error_control(".cub file only Error", NULL, 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 || is_cub(av[1]))
		error_control("worng argument Error", NULL, 1);
	ft_init(&data);
	parser(av[1], &data.cub, &data);
	//print_info(&data.cub);
	loop(&data);
	return (0);
}
