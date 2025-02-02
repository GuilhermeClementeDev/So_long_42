#include "so_long.h"

void	ft_rectangular(t_game *game)
{
	int		i;

	i = 1;
	game->map_game.width_map = ft_strlen(game->map_game.map[0]);

	if (game->map_game.width_map == game->map_game.height_map)
		ft_error("Its a square,not a rectangular", 5, game);

	while (i < game->map_game.height_map)
	{
		if (ft_strlen(game->map_game.map[i]) != game->map_game.width_map)
			ft_error("Size of line map diferent", 5, game);
		i++;
	}
}
void	ft_check_walls(char **map, int height, int width, t_game *game)
{
	int	i;
	int	k;
	const char *valid_chars = "10CEP";

	i = 0;
	while (i < height)
	{
		if ((map[i][0] != '1') || (map[i][width - 1] != '1'))
				ft_error("Invalid wall in the sides", 7, game);
		k = 0;
		while (map[i][k])
		{
			if (!ft_strchr(valid_chars, map[i][k]))
				ft_error("Map contains invalid character.", 6, game);
			if ((i == 0 || i == height - 1) && map[i][k] != '1')
				ft_error("Invalid wall first or last row", 7, game);
			k++;
		}
		i++;
	}
}
void	ft_check_countents(t_game *game)
{
	int	i;
	int	k;

	i = 1;
	while (i < game->map_game.height_map - 1)
	{
		k = 1;
		while (k < game->map_game.width_map - 1)
		{
			if (game->map_game.map[i][k] == 'C')
				game->map_game.c++;
			if (game->map_game.map[i][k] == 'P')
			{
				game->map_game.player.width = k;
				game->map_game.player.height = i;
				game->map_game.player.count++;
			}
			if (game->map_game.map[i][k] == 'E')
				game->map_game.exit++;
			k++;
		}
		i++;
	}
}
void	ft_validate_contents(t_game *game)
{
	if ((game->map_game.height_map <= 2) || (game->map_game.width_map <= 2))
		ft_error("Map has invalid size", 5, game);
	if (game->map_game.c < 1)
		ft_error("Map has invalid collectible number\nMust have at last one", 8, game);
	else if (game->map_game.exit != 1)
		ft_error("Map has invalid number of exits\n Must have only one", 9, game);
	else if (game->map_game.player.count != 1)
		ft_error("Map has invalid number of players\n Must have only one", 10, game);
}
void	ft_map_validation(t_game *game)
{
	game->map_game.c = 0;
	game->map_game.exit = 0;
	game->map_game.player.count = 0;

	ft_rectangular(game);
	ft_check_walls(game->map_game.map, game->map_game.height_map, game->map_game.width_map , game);
	ft_check_countents(game);
	ft_validate_contents(game);
}
