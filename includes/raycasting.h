/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:41:17 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/27 15:20:40 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "struct.h"

/*
 *
 */
void	horizontal_intersec(t_player *player, double current_ray, t_img_info *img);

/*
 *
 */
void	vertical_intersec(t_player *player, double current_ray, t_img_info *img);

#endif
