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

typedef struct s_sprit
{
	void		*img_ptr;
	int			size_x;
	int			size_y;
}	t_sprit;

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
	int			moves;
	t_sprit		wall;
	t_sprit		floor;
	t_sprit		collectible;
	t_sprit		exit_open;
	t_sprit		exit_close;
	t_sprit		player;
}	t_game;

void	ft_check_input(int argc, char **argv, t_game *game);

void	ft_error(char *str, int n, t_game *game);

void	ft_read_file(char *argv, t_game *game);

void	ft_map_validation(t_game *game);

void	ft_path_validation(t_game *game);

void	ft_open_mlx(t_game *game);

void	init_sprites(t_game *game);

int		render(t_game *game);
#endif
