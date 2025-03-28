/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:50:46 by guclemen          #+#    #+#             */
/*   Updated: 2025/03/24 09:50:48 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_and_move(t_game *game, int height, int width)
{
	if (game->map_game.map[height][width] == '1' || \
	game->map_game.map[height][width] == 'E')
	{
		if (game->map_game.map[height][width] == 'E' && !game->map_game.c)
		{
			game->moves++;
			ft_printf("Moviments: %d\n", game->moves++);
			ft_free_sprites(0, game);
		}
		return ;
	}
	game->map_game.map [game->map_game.player.height] \
	[game->map_game.player.width] = '0';
	if (game->map_game.map[height][width] == 'C')
		game->map_game.c--;
	game->map_game.map[height][width] = 'P';
	game->map_game.player.height = height;
	game->map_game.player.width = width;
	game->moves++;
}

int	ft_input(int key, t_game *game)
{
	if (key == 65307)
		ft_free_sprites(0, game);
	if (key == 119 || key == 65362)
		check_and_move(game, game->map_game.player.height - 1, \
		game->map_game.player.width);
	if (key == 115 || key == 65364)
		check_and_move(game, game->map_game.player.height + 1, \
		game->map_game.player.width);
	if (key == 100 || key == 65363)
		check_and_move(game, game->map_game.player.height, \
		game->map_game.player.width + 1);
	if (key == 97 || key == 65361)
		check_and_move(game, game->map_game.player.height, \
		game->map_game.player.width - 1);
	ft_render (game);
	return (0);
}

int	ft_x(t_game *game)
{
	ft_free_sprites(0, game);
	return (0);
}
