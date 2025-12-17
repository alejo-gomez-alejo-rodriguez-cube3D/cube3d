#ifndef PARSER_H
# define PARSER_H

int		parse_file(char *file_path, t_game *game);
char	*skip_spaces(char *line);
int		is_empty_line(char *line);
int		print_error(char *msg);
int	make_map_rectangular(t_game *game);
int		parse_texture(char *line, t_tex *tex, char *type);

int		parse_color(char *line, t_game *game, char type);

int     parse_map_line(char *line, t_game *game);

int	    validate_map(t_game *game);

int	check_walls(t_game *game);

int	free_game(t_game *game);

#endif