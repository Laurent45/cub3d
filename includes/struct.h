/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 08:11:12 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/21 17:24:17 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_seg
{
	t_point a;
	t_point	b;
}	t_seg;

typedef struct s_player
{
	t_point	pos;
	t_point	dir_view;
	double	angle_view;
}	t_player;

typedef struct s_core
{
	void		*mlx;
	void		*win;
	t_player	player;
}	t_core;

typedef struct s_img_info
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;	
}	t_img_info;

typedef struct s_hook
{
	struct s_core		*core;
	struct s_img_info	*img;
}	t_hook;

#endif
