#include "so_long.h"

void	ft_error(char *str, int n)
{
	ft_printf("Error :(\n%s\n", str);
	exit(n);
}
void	ft_read_file(char *argv)
{
	int		fd_map;
	char	*line_tmp;
	char	*map;
	int		tmp;

	fd_map = open(argv, O_RDONLY);
	if (fd_map == -1)
		ft_error("File couldn't be open. \nIs the file correct?", 2);
	map = ft_strdup("");
	while (1)
	{
		line_tmp = get_next_line(fd_map);
		if (!line_tmp)
			break ;
		map = join_and_free(map, line_tmp);
		free(line_tmp);
		tmp++;
	}
	tmp = ft_map_handler(map, tmp);
	free(map);
}

void	ft_check_input(int argc, char **argv)
{
	if (argc > 2)
		ft_error("Too many arguments \nShould be: ./so_long 'map.ber'", 1);
	else if (argc < 2)
		ft_error("The Map file is missing \nShould be: ./so_long 'map.ber'", 1);
	else if (!ft_strnstr(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		ft_error("Map file extention is wrong (It should be .ber).", 1);
}
