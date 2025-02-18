#include "so_long.h"

void	ft_error(char *str, int n, t_game *game)
{
	ft_putstr_fd("Error :(\n", 2);
	if (n == 3)
		ft_putstr_fd("Memory allocation failed.\n", 2);
	else
		ft_putstr_fd(str, 2);
	if (game)
	{
		if (game->map_game.malloc == 1)
		{
			int	i;

			i = 0;
			while (i < game->map_game.height_map)
			{
				free(game->map_game.map[i]);
				i++;
			}
			free(game->map_game.map);
		}
		free(game);
	}
	exit(n);
}
