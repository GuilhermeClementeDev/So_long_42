#include "so_long.h"

/*void	print_map(char **map, int height)
{
	int i = 0;
	while (i < height)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	ft_printf("\n");
}*/

static char **ft_copy_map(t_game *game)
{
	int	i;
	char	**cp;

	i = 0;
	cp = malloc((game->map_game.height_map + 1) * sizeof(char *));
	if (!cp)
		ft_error("", 3 ,game);
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

void	flood_fill(char **cp_map, int x, int y, t_game *game)
{
    if (cp_map[y][x] == '1' || cp_map[y][x] == 'F')
        return;

    cp_map[y][x] = 'F';

	//print_map(cp_map, game->map_game.height_map);

    flood_fill(cp_map, x + 1, y, game);
    flood_fill(cp_map, x - 1, y, game);
    flood_fill(cp_map, x, y + 1, game);
	flood_fill(cp_map, x, y - 1, game);
}
void	ft_path_exist(char **cp_map, t_game *game)
{
	int	i;
	int	k;

	i = 0;
	while (i < game->map_game.height_map)
	{
		k = 0;
		while (k < game->map_game.width_map)
		{
			if (cp_map[i][k] == 'C' || cp_map[i][k] == 'E')
			{
				i = 0;
				while (i < game->map_game.height_map)
					free (cp_map[i++]);
				free (cp_map);
				ft_error("Invalid Path", 11, game);
			}
			k++;
		}
		i++;
	}
}

void	ft_path_validation(t_game *game)
{
	char	**cp_map;

	cp_map = ft_copy_map(game);
	flood_fill(cp_map, game->map_game.player.width, game->map_game.player.height, game);
	ft_path_exist(cp_map, game);
}
