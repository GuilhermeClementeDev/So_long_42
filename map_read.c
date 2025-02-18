#include "so_long.h"

static void	ft_free_error(char *msg, char *map, t_game *game)
{
	free(map);
	ft_error(msg, 4, game);
}

static void	ft_new_line_handler(char *map, t_game *game)
{
	int	i;

	i = 0;
	if (map[0] == '\0')
		ft_free_error("Empty map.\n", map, game);
	if (map[0] == '\n')
		ft_free_error("Map has an empty line at the beginning.\n", map, game);
	if (map[ft_strlen(map) - 2] == '\n')
		ft_free_error("Map has an empty line at the end.\n", map, game);
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			ft_free_error("Map has an empty line in the middle.\n", map, game);
		i++;
	}
}

void	ft_read_file(char *argv, t_game *game)
{
	int		fd_map;
	char	*line_tmp;
	char	*map;

	game->map_game.height_map = 0;
	fd_map = open(argv, O_RDONLY);
	if (fd_map == -1)
		ft_error("File couldn't be opened. Is the file correct?", 2, game);
	map = ft_strdup("");
	if (!map)
		ft_error("", 3, game);
	while ((line_tmp = get_next_line(fd_map)))
	{
		map = ft_join_gnl(map, line_tmp);
		free(line_tmp);
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
		ft_error("Too many arguments \nShould be: ./so_long 'map.ber'\n", 1, game);
	else if (argc < 2)
		ft_error("The Map file is missing \nShould be: ./so_long 'map.ber'\n", 1, game);
	else if (!ft_strnstr(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		ft_error("Map file extention is wrong (It should be .ber).\n", 1, game);
}
