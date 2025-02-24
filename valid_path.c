#include "so_long.h"

static char	**ft_copy_map(t_game *game)
{
	int		i;
	char	**cp;

	i = 0;
	cp = malloc((game->map_game.height_map + 1) * sizeof(char *));
	if (!cp)
		ft_error ("", 3, game);
	while (i < game->map_game.height_map)
	{
		cp[i] = ft_strdup(game->map_game.map[i]);
		if (!cp[i])
		{
			while (i >= 0)
			{
				free(cp[i]);
				i--;
			}
			free(cp);
			ft_error("", 3, game);
		}
		i++;
	}
	cp[i] = NULL;
	return (cp);
}

static void	flood_fill(char **cp_map, int x, int y, t_game *game)
{
	if (cp_map[y][x] == 'E')
		cp_map[y][x] = 'K';
	if (cp_map[y][x] == '1' || cp_map[y][x] == 'F' || cp_map[y][x] == 'K')
		return ;
	cp_map[y][x] = 'F';
	flood_fill(cp_map, x + 1, y, game);
	flood_fill(cp_map, x - 1, y, game);
	flood_fill(cp_map, x, y + 1, game);
	flood_fill(cp_map, x, y - 1, game);
}

static void	ft_path_exist(char **cp_map, t_game *game)
{
	int	i;
	int	k;
	int	error;

	i = 0;
	error = 0;
	while (i < game->map_game.height_map && error == 0)
	{
		k = 0;
		while (k < game->map_game.width_map && error == 0)
		{
			if (cp_map[i][k] == 'C' || cp_map[i][k] == 'E')
				error = -1;
			k++;
		}
		i++;
	}
	i = 0;
	while (i < game->map_game.height_map)
		free (cp_map[i++]);
	free (cp_map);
	if (error == -1)
		ft_error("Invalid Path\n", 11, game);
}

void	ft_path_validation(t_game *game)
{
	char	**cp_map;

	cp_map = ft_copy_map(game);
	flood_fill(cp_map, game->map_game.player.width, \
		game->map_game.player.height, game);
	ft_path_exist(cp_map, game);
}
