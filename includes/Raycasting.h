/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:12:59 by ldubuche          #+#    #+#             */
/*   Updated: 2022/10/10 16:42:35 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

/*Je te laisse mettre tes structures ici ;p*/

# include "Parsing.h"

# define WIN_WIDTH	1440.0
# define WIN_HEIGHT	880.0
# define WIN_TITLE	"Cub3d"
# define WALL_SIZE	5

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

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_rect
{
	t_point center;
	double	l_width;
	double	l_height;
	int		color;
}	t_rect;

typedef struct s_view
{
	double	angle;
	t_point	v_front;
	t_point	v_side;
}	t_view;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir;
	double	f_front;
	double	f_side;
}	t_player;

typedef struct s_raycast
{
	t_pos	*best_point;
	double	dist;
	t_pos	horizontal;
	t_pos	vertical;
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

/**
 *
 */
int		init(t_map *map, t_core *core);

// Utils
double	set_angle(double angle);
double	to_rad(double angle);
double	to_rad(double angle);
int		is_wall(t_map *map, t_pos *a);
int		abs(int x);
void	put_pixel_img(t_img_info *img, int x, int y, int color);
void	set_position(t_pos *pos, double x, double y);

void	draw_segment(t_point a, t_point b, int color, t_img_info *img);
void	draw_rect_fill(t_rect *rect, t_img_info *img);
void	draw_rect(t_point center, int size, int color, t_img_info *img);
void	draw_map(t_img_info *img, t_map *map);
void	draw_player(t_img_info *img, t_player *player, t_map *map);

#endif
