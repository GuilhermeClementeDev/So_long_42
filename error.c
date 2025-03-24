/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:48:03 by guclemen          #+#    #+#             */
/*   Updated: 2025/03/24 09:48:05 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_msg(char *str, int n)
{
	int	std;

	if (n == 0)
		std = 1;
	else
	{
		std = 2;
		ft_putstr_fd("Error :(\n", std);
	}
	if (n == 3)
		ft_putstr_fd("Memory allocation failed.\n", std);
	else
		ft_putstr_fd(str, std);
}

void	ft_error(char *str, int n, t_game *game)
{
	int	i;

	i = 0;
	ft_msg(str, n);
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

void	ft_free_sprites(int n, t_game *game)
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
	if (n != 0)
		ft_error_mlx("Failed to generate image from xpm\n", n, game);
	else
		ft_error_mlx("Closing game...\n", n, game);
}
