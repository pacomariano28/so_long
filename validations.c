/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:27:48 by frmarian          #+#    #+#             */
/*   Updated: 2024/12/03 13:08:16 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_edges(t_game game)
{
	if (!all_chars_same(game.map[0], WALL)
		|| !all_chars_same(game.map[(matrixlen(game.map) - 1)], WALL))
	{
		free_matrix(game.map);
		free_matrix(game.map_copy);
		error_msg("Error: validate_edges: chr differs from '1'");
	}
}

void	validate_body(t_game game, t_entities *entities)
{
	int	len;
	int	i;

	entities->player_counter = 0;
	entities->coin_counter = 0;
	entities->exit_counter = 0;
	len = ft_strlen_gnl(game.map[0]);
	i = 1;
	while (game.map[i])
	{
		count_entities(game.map[i], entities);
		if (!validate_walls(game.map[i]) || !validate_len(game.map[i], len))
		{
			free_matrix(game.map);
			free_matrix(game.map_copy);
			error_msg("Error: walls or len are incorrect.");
		}
		i++;
	}
	validate_entities(entities, &game);
}

bool	validate_walls(char *lines)
{
	if (lines[0] != WALL || lines[ft_strlen_gnl(lines) - 1] != WALL)
		return (false);
	return (true);
}

bool	validate_len(char *str, int len)
{
	if (ft_strlen_gnl(str) != len)
		return (false);
	return (true);
}

void	validate_entities(t_entities *entities, t_game *game)
{
	if (entities->player_counter != 1
		|| entities->exit_counter != 1
		|| entities->coin_counter < 1)
	{
		free_all(game);
		error_msg("Error: validate_entities: wrong entities counter");
	}
}
