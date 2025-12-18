/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:04:24 by alejandro         #+#    #+#             */
/*   Updated: 2025/12/17 19:04:27 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define KEY_W 119
# define KEY_D 97
# define KEY_S 115
# define KEY_A 100
# define LEFT 65361
# define KEY_ESC 65307
# define RIGHT 65363
# define ENTER 65293

// struct raycasting

typedef struct s_ray
{
    double camera_x;
    double ray_dir_x;
    double ray_dir_y;

    int map_x;
    int map_y;

    double side_dist_x;
    double side_dist_y;

    double delta_dist_x;
    double delta_dist_y;

    int step_x;
    int step_y;

    int hit;
    int side;

    double perp_wall_dist;

    int line_height;
    int draw_start;
    int draw_end;
	
    int tex_x;
    int tex_y;
} t_ray;

// imagen en el MLX
typedef struct s_img
{
	void *img_mlx; // puntero a la imagen de MLX (mlx_new_image)
	char *addr;    // puntero al buffer (mlx_get_data_addr)
	int width;     // ancho de pixeles de la imagen
	int height;    // alto de pixeles de la imagen
	int bit_pp;    // bits por pixel
	int line_len;  // bytes por fila
	int endian;    // endianness (MLX llena)
}			t_img;

// textura
typedef struct s_tex
{
	void *img_mlx; // puntero a la imagen MLX (textura)
	char *addr;    // buffer a la textura
	char	*path;
	int		width;
	int		height;
	int		bit_pp; //bits por pixel
	int		line_len;
	int		endian;
}			t_tex;

// perspectiva del jugador
typedef struct s_dir_init
{
    char    dir;
    double  dir_x;
    double  dir_y;
    double  plane_x;
    double  plane_y;
}   t_dir_init;

// información del jugador
typedef struct s_player
{
	double x;       // posicion eje x (coordenada continua, ej. 2.5)
	double y;       // posicion eje y (coorndenada continua)
	double dir_x;   // vector direccion x (unitario)
	double dir_y;   // vector direccion y (unitario)
	double plane_x; // plano de la camara x (para FOV)
	double plane_y; // plano de la camara y
	char  dir_char; //'N', 'S', 'E', 'W' direccion inicial desde el parser
}			t_player;

// información del mapa
typedef struct s_map
{
	char **map; // matriz del mapa que debe venir del parser
	int rows;   // opcional ver para que se usa bien
	int cols;   // opcional ver para que usarlo
}			t_map;

// colores y caracteristicas del mapa
typedef struct s_config
{
	t_tex	tex_north;
	t_tex	tex_south;
	t_tex	tex_east;
	t_tex	tex_west;
	t_tex	tex_door;
	t_tex	tex_sprite;
	int color_floor;   // color suelo
	int color_ceiling; // ver la opcion de poner la parte del bonus

	int is_floor_set; // 1 si ya leímos el color del suelo
	int is_ceil_set;  // 1 si ya leímos el color del techo
}			t_config;

// estructura general para las estructuras
typedef struct s_game
{
	void *img_mlx;     // iniciar una sola vez, es la ventana del mlx_init()
	void *window;      // ventana MLX (mlx_new_window)
	t_img screen;      // imagen usada como backbuffer
	t_player player;   // datos del jugador
	t_map map;         // matriz del mapa
	t_config config;   // texturas y colores
	int win_w;         // nchura de la ventana
	int win_h;        // altura de la ventana
	double move_speed; // velocidad de movimiento (units/sec)
	double rot_speed;  // velocidad de rotacion (rad/sec)
	int runnig;        // flag para el loop 1 = running 0 = salir
}			t_game;


//free mem
int	destroy_game(t_game *g);

# include "parser.h"
# include "render.h"
#endif
