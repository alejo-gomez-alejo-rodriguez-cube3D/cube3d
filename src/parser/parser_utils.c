
#include "../../includes/cub3d.h"

char	*skip_spaces(char *line)
{
	while (line && *line && (*line == ' ' || *line == '\t'))
		line++;
	return (line);
}


int	is_empty_line(char *line)
{
	char	*ptr;

	ptr = skip_spaces(line);
	if (!*ptr || *ptr == '\n')
		return (1);
	return (0);
}

int	print_error(char *msg)
{
	printf("Error\n%s\n", msg);
	return (1);
}