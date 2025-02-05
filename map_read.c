#include "so_long.h"

void	ft_new_line_handler(char *map, t_game *game)
{
	int	i;

	i = 0;
	if (!map || map[0] == '\0')
	{
		free(map);
		ft_error("Empty map.", 4, game);
	}
	if (map[0] == '\n')
	{
		free(map);
		ft_error("Map has an empty line at the beginning.", 4, game);
	}
	if (map[ft_strlen(map) - 2] == '\n')
	{
		free(map);
		ft_error("Map has an empty line at the end.", 4, game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error("Map has an empty line in the middle.", 4, game);
		}
		i++;
	}
}

void	ft_read_file(char *argv, t_game *game)
{
	int		fd_map;
	char	*line_tmp;
	char	*map;
	char	*tmp;

	game->map_game.height_map = 0;
	fd_map = open(argv, O_RDONLY);
	if (fd_map == -1)
		ft_error("File couldn't be opened. Is the file correct?", 2, game);
	map = ft_strdup("");
	if (!map)
		ft_error("", 3, game);
	while ((line_tmp = get_next_line(fd_map)))
	{
		tmp = ft_strjoin(map, line_tmp);
		free(map);
		free(line_tmp);
		map = tmp;
		if (!map)
			ft_error("", 3, game);
		game->map_game.height_map++;
	}
	close(fd_map);
	ft_new_line_handler(map, game);
	game->map_game.map = ft_split(map, '\n');
	game->map_game.malloc = 1;
	free(map);
}

void	ft_check_input(int argc, char **argv, t_game *game)
{
	game->map_game.malloc = 0;

	if (argc > 2)
		ft_error("Too many arguments \nShould be: ./so_long 'map.ber'", 1, game);
	else if (argc < 2)
		ft_error("The Map file is missing \nShould be: ./so_long 'map.ber'", 1, game);
	else if (!ft_strnstr(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		ft_error("Map file extention is wrong (It should be .ber).", 1, game);
}
