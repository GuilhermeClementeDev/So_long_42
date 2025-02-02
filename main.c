#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	ft_check_input(argc, argv, game);
	ft_read_file(argv[1], game);
	ft_map_validation(game);
}
