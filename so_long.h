#ifndef SO_LONG_H
# define SO_LONG_H

#include "lib/libft.h"
#include <fcntl.h>

typedef struct s_map
{
	char		**map;
	int			width_map;
	int			height_map;
	int			wall;
	int			collectible;
	int			exit_map;
	int			player_qtd;
}	t_map;

typedef struct s_game
{
	t_map		map_game;
}	t_game;

void	ft_check_input(int argc, char **argv, t_game *game);

void	ft_error(char *str, int n, t_game *game);

void	ft_read_file(char *argv, t_game *game);

ft_map_validation(t_game *game);

#endif
