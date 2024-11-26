/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:52:43 by frmarian          #+#    #+#             */
/*   Updated: 2024/11/26 11:59:32 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	new_sprite(t_game *game, char *path, const char *entity)
{
	t_image	sprite;

	sprite.img = mlx_xpm_file_to_image(game->mlx, path, &sprite.x, &sprite.y);
	if (!sprite.img)
	{
		destroy_images(game);
		free_all(game);
		error_msg(ft_strjoin("Couldn't find a sprite of ", entity));
	}
	return (sprite);
}

void	find_sprite(t_game *game, int y, int x)
{
	char	coords;

	coords = game->map_copy[y][x];
	if (coords == WALL)
		render_sprite(game, game->wall_img, y, x);
	else if (coords == FLOOR)
		render_sprite(game, game->floor_img, y, x);
	else if (coords == COIN)
		render_sprite(game, game->coin_img, y, x);
	else if (coords == EXIT)
		render_sprite(game, game->exit_img, y, x);
	else if (coords == PLAYER)
		render_player (game, y, x);
}

void	render_sprite(t_game *game, t_image sprite, int line, int column)
{
	mlx_put_image_to_window(game->mlx, game->win, sprite.img, \
	column * TILE_SIZE, line * TILE_SIZE);
}

void	render_player(t_game *game, int y, int x)
{
	if (game->player_sprite == FRONT)
		render_sprite (game, game->player_front, y, x);
	if (game->player_sprite == LEFT)
		render_sprite (game, game->player_left, y, x);
	if (game->player_sprite == RIGHT)
		render_sprite (game, game->player_right, y, x);
	if (game->player_sprite == BACK)
		render_sprite (game, game->player_back, y, x);
}

void	init_sprites(t_game *game)
{
	game->floor_img = new_sprite(game, "images/floor.xpm", "Floor");
	game->player_front = new_sprite(game, "images/player.xpm", "Player");
	game->player_back = new_sprite(game, "images/back.xpm", "Player");
	game->player_right = new_sprite(game, "images/right.xpm", "Player");
	game->player_left = new_sprite(game, "images/left.xpm", "Player");
	game->coin_img = new_sprite(game, "images/coin.xpm", "Coin");
	game->exit_img = new_sprite(game, "images/exit.xpm", "Exit");
	game->wall_img = new_sprite(game, "images/wall.xpm", "Wall");
	game->player_sprite = FRONT;
}
