/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   missing_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:17:44 by ldubuche          #+#    #+#             */
/*   Updated: 2022/09/28 14:34:25 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	missing_info(t_map **map)
{
	if (!(*map))
		return (1);
	if (!(*map)->map)
		return (1);
	if ((*map)->width == 0 || (*map)->height == 0)
		return (1);
	if (!(*map)->texture)
		return (1);
	if (!(*map)->texture->so_texture || !(*map)->texture->no_texture \
		|| !(*map)->texture->ea_texture || !(*map)->texture->we_texture)
		return (1);
	if ((*map)->texture->floor_rgb == -1 || (*map)->texture->ceiling_rgb == -1)
		return (1);
	if ((*map)->direction == NO_DIRECTION)
		return (1);
	return (0);
}
