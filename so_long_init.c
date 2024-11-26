/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:37:47 by frmarian          #+#    #+#             */
/*   Updated: 2024/11/26 11:59:25 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_game *game)
{
	int	win_width;
	int	win_height;

	win_width = game->map_width * TILE_SIZE;
	win_height = game->map_height * TILE_SIZE;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_all(game);
		error_msg("Error: mlx can't initialise");
	}
	game->win = mlx_new_window(game->mlx, win_width, win_height, "so_long");
	if (!game->win)
	{
		free_all(game);
		error_msg("Error: mlx can't create a window");
	}
}

int	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map_copy[y])
	{
		x = 0;
		while (game->map_copy[y][x])
		{
			find_sprite(game, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
