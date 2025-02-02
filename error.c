#include "so_long.h"

void	ft_error(char *str, int n, t_game *game)
{
	ft_printf("Error :(\n");
	if (n == 3)
		ft_printf("Memory allocation failed.\n");
	else
		ft_printf("%s\n", str);

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
	exit(n);
}
