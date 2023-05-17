/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:23:58 by junhyupa          #+#    #+#             */
/*   Updated: 2023/05/17 16:38:49 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// void	free_all(t_cub *cub)
// {
// 	int	i;

// 	i = 0;
// 	free_box(cub->map);
// 	while(i < 4)
// 		free(cub->img[i++].path);
// }

void	free_box(char **box)
{
	int	i;

	i = 0;
	while(box && box[i])
		free(box[i++]);
	free(box[i]);
	free(box);
}
