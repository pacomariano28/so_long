/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:21:46 by frmarian          #+#    #+#             */
/*   Updated: 2024/11/28 14:03:19 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_validation(t_game *game, char *map_file)
{
	validate_extension(map_file);
	set_map(game, map_file);
	validate_edges(*game);
	validate_body(*game, &game->entities);
	find_player(game->map, &game->player_pos);
	reachable_entities(game, game->entities, game->player_pos);
	set_map_dimension(game);
	set_move_counter(game);
}

void	validate_extension(char *map)
{
	char	*extension;

	extension = ft_strrchr(map, '.');
	if (!extension || ft_strncmp(extension, ".ber", 5))
		error_msg("Error: not valid extension.");
}

char	*txt_to_line(char *txt)
{
	int		fd;
	char	*super_line;

	fd = open(txt, O_RDONLY);
	if (fd == -1)
		error_msg("Error: map does not exist.");
	super_line = process_txt(fd);
	close(fd);
	return (super_line);
}

char	*process_txt(int fd)
{
	char	*super_line;
	char	*gnl_line;

	super_line = ft_strdup("");
	gnl_line = get_next_line(fd);
	if (!gnl_line)
	{
		free(super_line);
		error_msg("Error: converting text to line");
	}
	while (gnl_line)
	{
		super_line = gnl_cat(super_line, gnl_line);
		free(gnl_line);
		gnl_line = get_next_line(fd);
	}
	check_line(super_line);
	return (super_line);
}

void	check_line(char *super_line)
{
	int	i;

	i = 0;
	while (super_line[i])
	{
		if (super_line[i] != WALL \
		&& super_line[i] != PLAYER \
		&& super_line[i] != EXIT \
		&& super_line[i] != FLOOR \
		&& super_line[i] != COIN \
		&& super_line[i] != '\n')
		{
			free(super_line);
			error_msg("Error: invalid map format");
		}
		i++;
	}
}
