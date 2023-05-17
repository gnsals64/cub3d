/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:12:49 by junhyupa          #+#    #+#             */
/*   Updated: 2023/05/17 16:09:59 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ERR_H
# define ERR_H

# include "cub3d.h"

void	*safe_calloc(size_t n, size_t size);
void	print_err(char *msg, char *msg2);
void	error_control(char *msg, char *msg2, int n);

void	free_all(t_cub *cub);
void	free_box(char **box);

#endif