/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:17:05 by frmarian          #+#    #+#             */
/*   Updated: 2024/11/26 11:27:43 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		map_validation(&game, av[1]);
		init_mlx(&game);
		init_sprites(&game);
		render_map(&game);
		mlx_hook(game.win, KeyPress, KeyPressMask, handle_input, &game);
		mlx_hook(game.win, DestroyNotify, \
		ButtonPressMask, close_game, &game);
		mlx_hook(game.win, Expose, ExposureMask, render_map, &game);
		mlx_loop(game.mlx);
	}
	else
		error_msg("Error: diff params expected");
	return (0);
}
