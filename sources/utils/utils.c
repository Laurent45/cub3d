/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:08:48 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/26 13:52:28 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	set_values(t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
}

int	abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}
