/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 08:41:43 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/26 19:57:48 by lfrederi         ###   ########.fr       */
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
void	main_img(t_core *core);


#endif
