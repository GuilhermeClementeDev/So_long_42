#include "so_long.h"

static char **ft_copy_map(t_game *game)
{
	int	i;
	char	**cp;

	i = 0;
	cp = malloc((game->map_game.height_map + 1) * sizeof(char *))
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

void	ft_path_validation(t_game *game)
{
	char	**cp_map;

	cp_map = ft_copy_map(game);
}
