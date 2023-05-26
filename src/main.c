/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:40:17 by hupa              #+#    #+#             */
/*   Updated: 2023/05/26 16:44:04 by hunpark          ###   ########.fr       */
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
	ft_init(&data, av[1]);
	loop(&data);
	return (0);
}
