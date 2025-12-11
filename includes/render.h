#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"

typedef struct s_game t_game;

//renders
int	load_all_textures(t_game *g);
int	load_texture(t_game *g, t_tex *tex);
int	init_mlx(t_game *game);
void	set_hook(t_game *game);
int	game_loop(t_game *g);

//int	init_structs(t_game *g);
int	key_press(int key, t_game *g);
int	close_window(t_game *g);

#endif
