#include "so_long.h"

static void	put_to_window(t_game *game, char element, int row, int col)
{
	void	*mlx;
	void	*win;
	void	*img_ptr;

	mlx = game->mlx;
	win = game->win;
	if (element == '0')
		img_ptr = game->floor.img_ptr;
	if (element == '1')
		img_ptr = game->wall.img_ptr;
	if (element == 'C')
		img_ptr = game->collectible.img_ptr;
	if (element == 'E')
	{
		if (game->map_game.c != 0)
			img_ptr = game->exit_close.img_ptr;
		else
			img_ptr = game->exit_open.img_ptr;
	}
	if (element == 'P')
		img_ptr = game->player.img_ptr;
	if (img_ptr != NULL)
		mlx_put_image_to_window(mlx, win, img_ptr, (col * 64), (row * 64));
}

int	render(t_game *game)
{
	int		i;
	int		k;
	char	*print_moviments;
	char	*str_num;

	i = 0;
	while (i < game->map_game.height_map)
	{
		k = 0;
		while (k < game->map_game.width_map)
		{
			put_to_window(game, game->map_game.map[i][k], i, k);
			k++;
		}
		i++;
	}
	str_num = ft_itoa(game->moves);
	print_moviments = ft_strjoin("Moviments: ", str_num);
	ft_printf("%s\n", print_moviments);
	free(str_num);
	free(print_moviments);
	return (0);
}
