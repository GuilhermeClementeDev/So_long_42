#include "so_long.h"

void	ft_error(char *str, int n, t_game *game)
{
	int	i;

	i = 0;
	ft_putstr_fd("Error :(\n", 2);
	if (n == 3)
		ft_putstr_fd("Memory allocation failed.\n", 2);
	else
		ft_putstr_fd(str, 2);
	if (game)
	{
		if (game->map_game.malloc == 1)
		{
			while (i < game->map_game.height_map)
			{
				free(game->map_game.map[i]);
				i++;
			}
			free(game->map_game.map);
		}
		free(game);
	}
	exit(n);
}
void	ft_error_mlx(char *msg, int n, t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	ft_error(msg, n, game);
}
void	ft_free_sprites(t_game *game)
{
	if (game->wall.img_ptr)
		mlx_destroy_image(game->mlx, game->wall.img_ptr);
	if (game->player.img_ptr)
		mlx_destroy_image(game->mlx, game->player.img_ptr);
	if (game->floor.img_ptr)
		mlx_destroy_image(game->mlx, game->floor.img_ptr);
	if (game->exit_open.img_ptr)
		mlx_destroy_image(game->mlx, game->exit_open.img_ptr);
	if (game->exit_close.img_ptr)
		mlx_destroy_image(game->mlx, game->exit_close.img_ptr);
	if (game->collectible.img_ptr)
		mlx_destroy_image(game->mlx, game->collectible.img_ptr);
	ft_error_mlx("Failed to generate image from xpm\n", 13, game);
}
