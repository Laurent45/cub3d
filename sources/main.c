/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:45:47 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/21 15:39:31 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "init.h"
#include "mlx.h"

#include <stddef.h>

void	create_map(t_core *core, t_img_info *img);

int	main()
{
	t_core		core;
	t_img_info	img;
	t_hook		hook;

	init_mlx(&core);
	img.img = NULL;
	init_hook(&hook, &core, &img);
	create_img(&core, &img);
	
	mlx_loop(core.mlx);

	return (0);
}

