/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 08:11:12 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/06 08:49:26 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define SUCCESS	0
# define FAILED		1

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

typedef struct s_view
{
	double	angle;
	t_point	v_front;
	t_point	v_side;
}	t_view;

typedef struct s_player
{
	t_point	pos;
	t_point	map_pos;
	t_point	tmp_pos;
	t_view	view;
	double	f_front;
	double	f_side;
}	t_player;

typedef struct s_raycast
{
	t_point	*best_point;
	double	dist;
	t_point	horizontal;
	t_point	vertical;
}	t_raycast;

typedef struct s_img_info
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;	
}	t_img_info;

typedef struct s_core
{
	void		*mlx;
	void		*win;
	t_img_info	main_img;
	t_player	player;
}	t_core;


#endif
