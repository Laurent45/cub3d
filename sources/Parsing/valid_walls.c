/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:37:58 by ldubuche          #+#    #+#             */
/*   Updated: 2022/09/27 15:12:43 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

t_state	change_state(int c, t_state state)
{
	if (state == WALL)
	{
		if (c == 3)
			return (OUTSIDE);
		if (c == 0 || c == 2)
			return (INSIDE);
	}
	else if (state == OUTSIDE)
	{
		if (c == 1)
			return (WALL);
		if (c == 0 || c == 2)
			return (FALSE);
	}
	else if (state == INSIDE)
	{
		if (c == 3)
			return (FALSE);
		if (c == 1)
			return (WALL);
	}
	return (state);
}

int	verif_horizontal(int x, int y, t_state state, t_map *map)
{
	while (y < map->height)
	{
		x = 0;
		state = OUTSIDE;
		while (x < map->width)
		{
			state = change_state(map->map[y][x], state);
			if (state == FALSE)
				return (1);
			x++;
		}
		if (state == INSIDE)
			return (1);
		y++;
	}
	return (0);
}

int	verif_vertical(int x, int y, t_state state, t_map *map)
{
	while (x < map->width)
	{
		y = 0;
		state = OUTSIDE;
		while (y < map->height)
		{
			state = change_state(map->map[y][x], state);
			if (state == FALSE)
				return (1);
			y++;
		}
		if (state == INSIDE)
			return (1);
		x++;
	}
	return (0);
}

int	valid_walls(t_map *map)
{
	int		x;
	int		y;
	t_state	state;

	x = 0;
	y = 0;
	state = OUTSIDE;
	if (!verif_horizontal(x, y, state, map))
		return (1);
	if (!verif_vertical(x, y, state, map))
		return (1);
	return (0);
}
