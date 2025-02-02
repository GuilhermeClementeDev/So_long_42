#include "so_long.h"

void	ft_error(char *str, int n, t_game *game)
{
	if (n == 3)
		ft_printf("Memory allocation failed.\n");
	else
		ft_printf("Error :(\n%s\n", str);
	free(game);
	exit(n);
}
