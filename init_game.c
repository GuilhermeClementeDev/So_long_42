#include "so_long.h"

void	ft_open_mlx(t_game *game)
{
	int	width_win;
	int	height_win;

	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_error("Error of mlx_init\n", 12, game);
	width_win = game->map_game.width_map * 64;
	height_win = game->map_game.height_map * 64;
	game->win = mlx_new_window(game->mlx, width_win, height_win, "so_long");
	if (game->win == NULL)
		ft_error_mlx("Error creating a window\n", 12, game);
}

static t_sprite	ft_get_img(void *mlx, char *path, t_game *game)
{
	t_sprite	img;

	img.img_ptr = mlx_xpm_file_to_image(mlx, path, &img.size_x, &img.size_y);
	if (img.img_ptr == NULL)
		ft_free_sprites(game);
	return (img);
}

void	ft_init_sprites(t_game *game)
{
	game->wall.img_ptr = NULL;
	game->player.img_ptr = NULL;
	game->floor.img_ptr = NULL;
	game->exit_open.img_ptr = NULL;
	game->exit_close.img_ptr = NULL;
	game->collectible.img_ptr = NULL;
	game->wall = ft_get_img(game->mlx, "textures/wall2.xpm", game);
	game->player = ft_get_img(game->mlx, "textures/player.xpm", game);
	game->floor = ft_get_img(game->mlx, "textures/floor.xpm", game);
	game->exit_open = ft_get_img(game->mlx, "textures/exit_open.xpm", game);
	game->exit_close = ft_get_img(game->mlx, "textures/exit_close.xpm", game);
	game->collectible = ft_get_img(game->mlx, "textures/c.xpm", game);
}
