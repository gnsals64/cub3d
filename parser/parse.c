/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:57:27 by junhyupa          #+#    #+#             */
/*   Updated: 2023/05/22 19:47:44 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	is_alldigit(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (len == 0 || (len > 3 && s[3] != '\n'))
		return (0);
	while (s && *s)
	{
		if (!ft_isdigit(*s) && *s != '\n')
			return (0);
		s++;
	}
	return (1);
}

static int		parse_color(char *s)
{
	int		tmp;
	int		i;
	char	**box;

	box = ft_split(s, ',');
	i = 0;
	tmp = 0;
	while(box && box[i] && i < 3)
	{
		if (!is_alldigit(box[i]))
			error_control("cub file Error1", NULL, 1);
		tmp = tmp << 8;
		tmp += atoi(box[i]);
		i++;
	}
	if (!box || box[i])
		error_control("cub file Error2", NULL, 1);
	free_box(box);
	return (tmp);
}

static char	*skip_space(char *s)
{
	while(s && *s && *s == ' ')
		s++;
	return (s);
}

static void	parse_option(int fd, t_cub *cub)
{
	char	*tmp;
	int		cnt;

	cnt = 0;
	tmp = get_next_line(fd);
	while(cnt < 6 && tmp && *tmp)
	{
		if (!cub->texture[NO].path && !ft_strncmp(tmp, "NO ", 3) && ++cnt)
			cub->texture[NO].path = ft_strdup(skip_space(&tmp[3]));
		else if (!cub->texture[WE].path && !ft_strncmp(tmp, "WE ", 3) && ++cnt)
			cub->texture[WE].path = ft_strdup(skip_space(&tmp[3]));
		else if (!cub->texture[SO].path && !ft_strncmp(tmp, "SO ", 3) && ++cnt)
			cub->texture[SO].path = ft_strdup(skip_space(&tmp[3]));
		else if (!cub->texture[EA].path && !ft_strncmp(tmp, "EA ", 3) && ++cnt)
			cub->texture[EA].path = ft_strdup(skip_space(&tmp[3]));
		else if (!cub->f_color && !ft_strncmp(tmp, "F ", 2) && ++cnt)
			cub->f_color = parse_color(skip_space(&tmp[2]));
		else if (!cub->c_color && !ft_strncmp(tmp, "C ", 2) && ++cnt)
			cub->c_color = parse_color(skip_space(&tmp[2]));
		else if (ft_strncmp(tmp, "\n", 1) && cnt < 6)
			error_control("cub file Error3", NULL, 1);
		free(tmp);
		if (cnt < 6)
			tmp = get_next_line(fd);
	}
}

void	texture_init(t_data *data)
{
	t_cub	*cub;
	int	i;

	cub = &data->cub;
	i = 0;
	while (i < 4)
		cub->texture[i].texture = mlx_xpm_file_to_image(data->mlx.mlx_ptr, \
			cub->texture[i].path, &cub->texture[i].texture_width, &cub->texture[i].texture_height);
}

void	parser(char *av, t_cub *cub, t_data *data)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		error_control(strerror(errno), "file open Error", 1);
	parse_option(fd, cub);
	parse_map(fd, cub);
	close(fd);
	map_checker(cub->map, cub, data);
}
