/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:04:24 by alejandro         #+#    #+#             */
/*   Updated: 2026/01/16 21:33:57 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include "../bonus/bonus.h"
# include "parser.h"
# include "render.h"

# define KEY_W 119
# define KEY_D 97
# define KEY_S 115
# define KEY_A 100
# define RIGHT 65361
# define KEY_ESC 65307
# define KEY_E 101
# define LEFT 65363
# define ENTER 65293

# define WALL_MARGIN 0.2
# define MIN_WALL_DIST 0.1
# define MOVE_SPEED_BASE 4.5
# define ROT_SPEED_BASE 2.5
# define MOUSE_SENS 2
// struct raycasting

typedef struct s_ray
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;

	int			map_x;
	int			map_y;

	double		side_dist_x;
	double		side_dist_y;

	double		delta_dist_x;
	double		delta_dist_y;

	double		tex_step;
	double		tex_pos;

	int			step_x;
	int			step_y;

	int		hit;
	int		side;
	int		hit_door;

	double		perp_wall_dist;

	int			line_height;
	int			draw_start;
	int			draw_end;

	int			tex_x;
	int			tex_y;
}				t_ray;

// puertas
typedef struct s_door
{
	int			x;
	int			y;
	int			open;
}				t_door;

typedef struct s_img
{
	void		*img_mlx;
	char		*addr;
	int			width;
	int			height;
	int			bit_pp;
	int			line_len;
	int			endian;
}				t_img;

// textura
typedef struct s_tex
{
	void		*img_mlx;
	char		*addr;
	char		*path;
	int			width;
	int			height;
	int			bit_pp;
	int			line_len;
	int			endian;
}				t_tex;

// perspectiva del jugador
typedef struct s_dir_init
{
	char		dir;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_dir_init;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	char		dir_char;
}				t_player;

// input de movimiento
typedef struct s_input
{
	int			forward;
	int			backward;
	int			strafe_left;
	int			strafe_right;
	int			rotate_left;
	int			rotate_right;
}				t_input;

// información del mapa
typedef struct s_map
{
	char		**map;
	int			rows;
	int			cols;
	int			has_ended;
}				t_map;

// colores y caracteristicas del mapa
typedef struct s_config
{
	t_tex		tex_north;
	t_tex		tex_south;
	t_tex		tex_east;
	t_tex		tex_west;
	t_tex		tex_door;
	t_tex		tex_sprite;
	int			color_floor;
	int			color_ceiling;

	int			is_floor_set;
	int			is_ceil_set;
}				t_config;

// estructura general para las estructuras
typedef struct s_game
{
	void		*img_mlx;
	void		*window;
	t_img		screen;
	t_player	player;
	t_input		input;
	t_map		map;
	t_config	config;

	int			win_w;
	int			win_h;

	double		last_time;
	double		delta_time;

	double		move_speed;
	double		rot_speed;

	int			runnig;
	int			mlx_initialized;
	int			bonus_enabled;

	int			mouse_initialized;
	int			mouse_x;
	int			press_e;

	t_door		*doors;
	int			count_doors;
}				t_game;

// time_game
double			get_time_ms(void);
void			get_delta_time(t_game *g);

// free mem
void			destroy_game(t_game *g);
void			free_map_array(t_game *game);
void			free_textures(t_game *game);

#endif
