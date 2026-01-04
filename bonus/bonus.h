/* bonus/bonus.h */

#ifndef BONUS_H
# define BONUS_H

# include "../includes/cub3d.h"

# define MM_SIZE 120    // Tamaño del cuadrado (ancho y alto)
# define MM_OFFSET_X 20 // Margen izquierdo desde el borde de ventana
# define MM_OFFSET_Y 20 // Margen superior
# define MM_ZOOM 12.0

# define C_MM_BG 0x000000     // Negro (Fuera del mapa)
# define C_MM_WALL 0x404040   // Gris Oscuro (Paredes)
# define C_MM_FLOOR 0xD0D0D0  // Gris Claro / Blanco (Suelo transitable)
# define C_MM_PLAYER 0xFF0000 // Rojo Puro (Tú)
# define C_MM_FRAME 0xFFFFFF  // Borde blanco alrededor del minimapa

void	draw_minimap(t_game *game);

#endif