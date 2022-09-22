/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:10:01 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/22 17:42:40 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "struct.h"

# define ESC			65307	
# define ARROW_LEFT		65361
# define ARROW_UP		65362
# define ARROW_RIGHT	65363
# define ARROW_DOWN		65364
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

/**
 *
 */
int		close_red(void *vars);

/**
 *
 */
int		key_press(int keycode, void *vars);

/**
 *
 */
void	press_esc(t_core *core);

/**
 *
 */
int		move_player(t_core *core, int keycode);

/**
 *
 */
void	move_dir_view(t_core *core, int keycode);

#endif
