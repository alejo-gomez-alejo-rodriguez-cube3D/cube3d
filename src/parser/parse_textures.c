#include "../../includes/cub3d.h"


static int	check_duplicate(char *path, char *type)
{
	if (path != NULL)
	{
		printf("Error\nDuplicate texture found: %s\n", type);
		return (1);
	}
	return (0);
}


int	parse_texture(char *line, t_tex *tex, char *type)
{
	char	*ptr;

	if (check_duplicate(tex->path, type))
		return (1);

	ptr = line + 2;

	tex->path = ft_strtrim(ptr, " \n\t");

	if (!tex->path)
		return (print_error("Memory allocation failed for texture path"));
	
	if (ft_strlen(tex->path) == 0)
	{
		free(tex->path);
		tex->path = NULL;
		return (print_error("Texture path is empty or invalid"));
	}
	return (0); 
}
