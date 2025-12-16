#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"

typedef struct s_game t_game;

//raycasting
void	raycast_scene(t_game *g);
void	init_ray(t_game *g, t_ray *r, int x);
void draw_column(t_game *g, t_ray *r, int x);
t_tex *select_wall_texture(t_game *g, t_ray *r);
void compute_tex_x(t_game *g, t_ray *r, t_tex *tex);

//dda_utils
void perform_dda(t_game *g, t_ray *r);
void dda_loop(t_game *g, t_ray *r);
void init_dda_y(t_game *g, t_ray *r);
void init_dda_x(t_game *g, t_ray *r);

//compute
void compute_wall(t_game *g, t_ray *r);
void compute_draw_limits(t_game *g, t_ray *r);
void compute_line_height(t_game *g, t_ray *r);
void compute_perp_dist(t_ray *r);

//renders
int	init_mlx(t_game *game);
int	game_loop(t_game *g);
void	init_constants(t_game *g);
int	init_game(t_game *g);

//hooks
void	set_hook(t_game *game);

//load_textures
int	load_all_textures(t_game *g);
int	load_texture(t_game *g, t_tex *tex);

//utils
void	blit_texture_center(t_game *g, t_tex *tex);
void	put_pixel(t_img *img, int x, int y, int color);
unsigned int	get_tex_pixel(t_tex *tx, int x, int y);

//buttons
int	key_press(int key, t_game *g);
int	close_window(t_game *g);

#endif
