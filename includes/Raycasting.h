/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:12:59 by ldubuche          #+#    #+#             */
/*   Updated: 2022/10/11 20:54:13 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

/*Je te laisse mettre tes structures ici ;p*/

# include "Parsing.h"

# define SUCCESS	0
# define FAILED		1
# define WIN_WIDTH	1440.0
# define WIN_HEIGHT	880.0
# define WIN_TITLE	"Cub3d"
# define ESC			65307
# define ARROW_LEFT		65361
# define ARROW_UP		65362
# define ARROW_RIGHT	65363
# define ARROW_DOWN		65364
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define DIR_INCR		5.0
# define FOV			60.0
# define NORTH			270.0
# define SOUTH			90.0
# define EAST			0.0
# define WEST			180.0
# define VELOCITY		5

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

/* typedef struct s_view */
/* { */
/* 	double	angle; */
/* 	t_point	v_front; */
/* 	t_point	v_side; */
/* }	t_view; */

typedef struct s_player
{
	t_pos	pos;
	t_pos	pos_tmp;
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
	int		width;
	int		height;
}	t_img_info;

typedef struct s_core
{
	void		*mlx;
	void		*win;
	t_img_info	main_img;
	t_player	player;
	t_map		*map;
}	t_core;

/**
 *
 */
int		init(t_map *map, t_core *core);
int		init_main_img(t_core *core, int width, int height);
void	init_hook(t_core *core);

// Utils
double	set_angle(double angle);
double	to_rad(double angle);
int		is_wall(t_map *map, t_pos *a, int dir);
int		abs(int x);
void	put_pixel_img(t_img_info *img, int x, int y, int color);
void	set_position(t_pos *pos, double x, double y);
void	pixel_point(t_point *a, t_pos *pos, t_core *core);
double	distance(t_pos *a, t_pos *b);

// Draw
void	draw_segment(t_point a, t_point b, int color, t_img_info *img);
void	draw_rect_fill(t_rect *rect, t_img_info *img);
void	draw_rect(t_rect *rect, t_img_info *img);
void	draw_map(t_img_info *img, t_map *map);
void	draw_player(t_core *core);

// Event
int		close_red(void *core);
int		key_press(int keycode, void *core);
void	move_dir(t_core *core, int keycode);
void	move_player(t_core *core, int keycode);
void	press_esc(t_core *core);

// Raycast
void	raycasting(t_core *core, t_rect *rect);

#endif
