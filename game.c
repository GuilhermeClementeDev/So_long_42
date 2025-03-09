#include "so_long.h"

static void	check_and_move(t_game *game, int height, int width)
{
	if (game->map_game.map[height][width] == '1' || game->map_game.map[height][width] == 'E')
	{
		if (game->map_game.map[height][width] == 'E' && !game->map_game.c)
			{
				ft_putstr_fd("Congratulations, you win!!\n", 1);
			}
		return ;
	}
	game->map_game.map[game->map_game.player.height][game->map_game.player.width] = '0';
	if (game->map_game.map[height][width] == 'C')
		game->map_game.c--;
	game->map_game.map[height][width] = 'P';
	game->map_game.player.height = height;
	game->map_game.player.width = width;
	game->moves++;
}
int	ft_input(int key, t_game *game)
{
	if (key == 65307)
	{

	}
	if (key == 119 || key == 65362)
		check_and_move(game, game->map_game.player.height - 1, game->map_game.player.width);
	if (key == 115 || key == 65364)
		check_and_move(game, game->map_game.player.height + 1, game->map_game.player.width);
	if (key == 100 || key == 65363)
		check_and_move(game, game->map_game.player.height, game->map_game.player.width + 1);
	if (key == 97 || key == 65361)
		check_and_move(game, game->map_game.player.height, game->map_game.player.width - 1);
	ft_render(game);
	return 0;
}
