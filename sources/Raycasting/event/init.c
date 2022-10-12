/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:53:05 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/12 13:53:57 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include "mlx.h"

void	init_hook(t_core *core)
{
	mlx_hook(core->win, 17, 1L << 17, close_red, core);
	mlx_hook(core->win, 2, 1L << 0, key_press, core);
}
