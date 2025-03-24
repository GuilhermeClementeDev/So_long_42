/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:52:16 by guclemen          #+#    #+#             */
/*   Updated: 2025/03/24 09:52:17 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_error("", 3, game);
	ft_check_input(argc, argv, game);
	ft_read_file(argv[1], game);
	ft_map_validation(game);
	ft_path_validation(game);
	ft_open_mlx(game);
	ft_init_sprites(game);
	ft_render(game);
	mlx_key_hook(game->win, ft_input, game);
	mlx_hook(game->win, 17, 0, ft_x, game);
	mlx_loop(game->mlx);
	return (0);
}
