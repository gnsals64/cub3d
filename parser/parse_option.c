/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:57:27 by junhyupa          #+#    #+#             */
/*   Updated: 2023/05/26 13:13:22 by junhyupa         ###   ########.fr       */
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

static int	parse_color(char *s)
{
	int		tmp;
	int		i;
	int		j;
	char	**box;

	box = ft_split(s, ',');
	i = 0;
	tmp = 0;
	while (box && box[i] && i < 3)
	{
		j = 0;
		while (box[i][j] == ' ')
			j++;
		if (!is_alldigit(&box[i][j]))
			error_control("Invalid color Error", NULL, 1);
		tmp = tmp << 8;
		tmp += atoi(&box[i][j]);
		i++;
	}
	if (!box || box[i])
		error_control("color parsing failed Error", NULL, 1);
	free_box(box);
	return (tmp);
}

static char	*skip_space(char *s)
{
	while (s && *s && *s == ' ')
		s++;
	return (s);
}

static int	get_option_value(t_cub *cub, char *tmp)
{
	if (!cub->texture[NO] && !ft_strncmp(tmp, "NO ", 3))
		cub->texture[NO] = ft_strdup(skip_space(&tmp[3]));
	else if (!cub->texture[WE] && !ft_strncmp(tmp, "WE ", 3))
		cub->texture[WE] = ft_strdup(skip_space(&tmp[3]));
	else if (!cub->texture[SO] && !ft_strncmp(tmp, "SO ", 3))
		cub->texture[SO] = ft_strdup(skip_space(&tmp[3]));
	else if (!cub->texture[EA] && !ft_strncmp(tmp, "EA ", 3))
		cub->texture[EA] = ft_strdup(skip_space(&tmp[3]));
	else if (!cub->f_color && !ft_strncmp(tmp, "F ", 2))
		cub->f_color = parse_color(skip_space(&tmp[2]));
	else if (!cub->c_color && !ft_strncmp(tmp, "C ", 2))
		cub->c_color = parse_color(skip_space(&tmp[2]));
	else if (ft_strncmp(tmp, "\n", 1))
		return (0);
	return (1);
}

void	parse_option(int fd, t_cub *cub)
{
	char	*tmp;
	int		cnt;

	cnt = 0;
	tmp = get_next_line(fd);
	while (cnt < 6 && tmp && *tmp)
	{
		if (ft_strlen(tmp) >= 1 && tmp[ft_strlen(tmp) - 1] == '\n')
			tmp[ft_strlen(tmp) - 1] = 0;
		if (!get_option_value(cub, tmp) && cnt < 6)
			error_control("Invalid option value error", NULL, 1);
		else
			++cnt;
		free(tmp);
		if (cnt < 6)
			tmp = get_next_line(fd);
	}
	if (cnt < 6)
		error_control("Need all options Error", NULL, 1);
}
