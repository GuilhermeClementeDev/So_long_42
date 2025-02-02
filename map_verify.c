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

void	ft_map_validation(t_game *game)
{
	ft_rectangular(game);
}
