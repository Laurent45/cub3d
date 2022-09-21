/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:51:53 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/21 18:17:16 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

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
int		close_red(void *hook);

/**
 *
 */
int		key_press(int keycode, void *hook);

/**
 *
 */
int		move_player(t_player *player, int keycode);

/**
 *
 */
void	move_dir_view(t_player *player, int keycode);

/**
 *
 */
void	press_esc(t_hook *hook);

#endif
