/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:44:44 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/28 15:45:29 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "mlx.h"

void	init_hook(t_core *core)
{
	mlx_hook(core->win, 17, 1L << 17, close_red, core);
	mlx_hook(core->win, 2, 1L << 0, key_press, core);
}
