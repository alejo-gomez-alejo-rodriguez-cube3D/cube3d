/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:47:26 by alejaro2          #+#    #+#             */
/*   Updated: 2026/01/16 21:42:48 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "../includes/cub3d.h"

# define MM_SIZE 120
# define MM_OFFSET_X 20
# define MM_OFFSET_Y 20
# define MM_ZOOM 12.0

# define C_MM_BG 0x000000
# define C_MM_WALL 0x404040
# define C_MM_FLOOR 0xD0D0D0
# define C_MM_PLAYER 0xFF0000
# define C_MM_FRAME 0xFFFFFF

typedef struct s_game	t_game;

void	draw_minimap(t_game *game);

// hooks_bonus
void	set_hook_bonus(t_game *game);
int		mouse_move(int x, int y, t_game *g);

// iniciador aparte
int		init_game_bonus(t_game *g);

// parser bonus
void	save_door(t_game *g, int x, int y);
void	free_doors(t_game *game);
int		is_door_close(t_game *g, int x, int y);
void	toggle_door(t_game *g);
void	door_toggle_state(t_game *g, int index);
int		find_door(t_game *g, int x, int y);
void	free_doors(t_game *game);

#endif