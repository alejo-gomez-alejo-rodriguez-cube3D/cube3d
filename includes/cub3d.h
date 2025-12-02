#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


# include "../libs/libft/include/libft.h" 

# include "parser.h"

//imagen en el MLX
typedef struct	s_img
{
	void	*img_mlx;	//puntero a la imagen de MLX (mlx_new_image)
	char	*addr;		//puntero al buffer (mlx_get_data_addr)
	int	width;		//ancho de pixeles de la imagen
	int	height;		//alto de pixeles de la imagen
	int	bit_pp;		//bits por pixel
	int	line_len;	//bytes por fila
	int	endian;		//endianness (MLX llena)
}		t_img;

//textura
typedef struct	s_tex
{
	void	*img_mlx;	//puntero a la imagen MLX (textura)
	char	*addr;		//buffer a la textura
	int	width;
	int	height;
	int	bit_pp;
	int	line_len;
	int	endian;	
}		t_tex;

//información del jugador
typedef struct s_player
{
	double	x;		//posicion eje x (coordenada continua, ej. 2.5)
	double	y;		//posicion eje y (coorndenada continua)
	double	dir_x;		//vector direccion x (unitario)
	double	dir_y;		//vector direccion y (unitario)
	double	plane_x;	//plano de la camara x (para FOV)
	double	plane_y;	//plano de la camara y
	char	*dir_char;	//'N', 'S', 'E', 'W' direccion inicial desde el parser
}		t_player;

//información del mapa
typedef	struct	s_map
{
	char	**map;		//matriz del mapa que debe venir del parser
	int	rows;		//opcional ver para que se usa bien
	int	cols;		//opcional ver para que usarlo
}		t_map;

//colores y caracteristicas del mapa
typedef struct	s_config
{
	t_tex	tex_north;
	t_tex	tex_south;
	t_tex	tex_east;
	t_tex	tex_west;
	int	color_floor;		//color suelo
	int	color_ceiling;		//color de cielo, ver la opcion de poner la parte del bonus
}		t_config;

//estructura general para las estructuras
typedef struct	s_game
{
	void		*img_mlx;	//iniciar una sola vez, es la ventana del mlx_init()
	void		*window;	//ventana MLX (mlx_new_window)
	t_img		screen;		//imagen usada como backbuffer
	t_player	player;		//datos del jugador
	t_map		map;		//matriz del mapa
	t_config	config;		//texturas y colores
	int		win_w;		//nchura de la ventana
	int		wind_h;		//altura de la ventana
	double		move_speed;	//velocidad de movimiento (units/sec)
	double		rot_speed;	//velocidad de rotacion (rad/sec)
	int		runnig;		//flag para el loop 1 = running 0 = salir
}		t_game;


#endif
