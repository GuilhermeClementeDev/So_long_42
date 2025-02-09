#include "so_long.h"

void	ft_open_mlx(t_game *game)
{
	int	width_win;
	int	height_win;

	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		free(game->mlx);
		ft_error("Error of initializetion, mlx", 12, game);
	}
	width_win = game->map_game.width_map * 64;
	height_win = game->map_game.height_map * 64;
	game->win = mlx_new_window(game->mlx, width_win, height_win, "so_long");
	if (game->win == NULL)
	{
		free(game->mlx);
		ft_error("Error creating a window", 12, game);
	}
}
