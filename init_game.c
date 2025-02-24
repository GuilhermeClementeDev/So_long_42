#include "so_long.h"

void	ft_open_mlx(t_game *game)
{
	int	width_win;
	int	height_win;

	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_error("Error of initializetion, mlx\n", 12, game);
	width_win = game->map_game.width_map * 64;
	height_win = game->map_game.height_map * 64;
	game->win = mlx_new_window(game->mlx, width_win, height_win, "so_long");
	if (game->win == NULL)
	{
		free(game->mlx);
		ft_error("Error creating a window\n", 12, game);
	}
}
static t_sprit	get_img(void *mlx, char *path, t_game *game)
{
	t_sprit	img;

	img.img_ptr = mlx_xpm_file_to_image(mlx, path, &img.size_x, &img.size_y);
	if (img.img_ptr == NULL)
	{
		free(img.img_ptr);
		ft_error("Error on creating a window", 12,game);
	}
	return (img);
}
void	init_sprites(t_game *game)
{
	game->wall = get_img(game->mlx, "textures/wall2.xpm", game);
	game->player = get_img(game->mlx, "textures/player.xpm", game);
	game->floor = get_img(game->mlx, "textures/floor.xpm", game);
	game->exit_open = get_img(game->mlx, "textures/exit_open.xpm", game);
	game->exit_close = get_img(game->mlx, "textures/exit_close.xpm", game);
	game->collectible = get_img(game->mlx, "textures/c.xpm", game);
}
