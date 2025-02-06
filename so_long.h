#ifndef SO_LONG_H
# define SO_LONG_H

#include "lib/libft.h"
#include <fcntl.h>
#include "mlx/mlx.h"

typedef struct s_position
{
	int	width;
	int	height;
	int	count;
}	t_player;

typedef struct s_map
{
	char		**map;
	int			width_map;
	int			height_map;
	int			wall;
	int			c;
	int			exit;
	int			malloc;
	t_player	player;
}	t_map;

typedef struct s_game
{
	t_map		map_game;
	void		*mlx;
	void		*win;
}	t_game;

void	ft_check_input(int argc, char **argv, t_game *game);

void	ft_error(char *str, int n, t_game *game);

void	ft_read_file(char *argv, t_game *game);

void	ft_map_validation(t_game *game);

void	ft_path_validation(t_game *game);

#endif
