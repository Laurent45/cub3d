/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 08:41:43 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/22 18:27:37 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

#include "struct.h"

/**
 *
 */
void	put_pixel_img(t_img_info *img, int x, int y, int color);

/**
 *
 */
void	create_img(t_core *core);

#endif
