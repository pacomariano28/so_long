/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:23:46 by frmarian          #+#    #+#             */
/*   Updated: 2024/06/12 11:10:17 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "lib/minilibx/mlx.h"
# include "lib/libft/libft.h"
# include <X11/X.h>

# define TILE_SIZE 70

// Entities definition
# define FLOOR '0'
# define WALL '1'
# define PLAYER 'P'
# define COIN 'C'
# define EXIT 'E'
# define VISITED 'V'

// Movements key ASCII
# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364

# define KEY_Q				113
# define KEY_ESC  			65307

# define FRONT				1
# define LEFT				2
# define RIGHT				3
# define BACK				4

typedef struct s_entities
{
	int	player_counter;
	int	exit_counter;
	int	coin_counter;
}	t_entities;

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_image
{
	void	*img;
	int		x;
	int		y;
}	t_image;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_image		floor_img;
	t_image		wall_img;
	t_image		player_front;
	t_image		player_right;
	t_image		player_left;
	t_image		player_back;
	int			player_sprite;
	t_image		coin_img;
	t_image		exit_img;
	char		**map;
	char		**map_copy;
	int			map_width;
	int			map_height;
	int			move_counter;
	t_coords	player_pos;
	t_entities	entities;
}	t_game;

// Map_validation.c
void		map_validation(t_game *game, char *map);
void		validate_extension(char *file);
char		*txt_to_line(char *txt);
char		*process_txt(int fd);

// set_map.c
void		set_map_dimension(t_game *game);
void		set_move_counter(t_game *game);
void		set_map(t_game *game, char *file);
void		check_line(char *super_line);

// Validations.c
void		validate_entities(t_entities *entities, t_game game);
void		validate_edges(t_game game);
void		validate_body(t_game game, t_entities *entities);
bool		validate_walls(char *lines);
bool		validate_len(char *str, int len);

// Validations_utils.c
void		count_entities(char *line, t_entities *entities);
void		find_player(char **map, t_coords *player_cords);
void		flood_fill(int x, int y, t_entities *entities, char **map);
void		reachable_entities(t_game *game, t_entities entities, \
			t_coords p_coords);
char		*gnl_cat(char *s1, char *s2);

// so_long_init.c
void		init_mlx(t_game *game);
int			render_map(t_game *game);

// sprite_utils.c
void		init_sprites(t_game *game);
t_image		new_sprite(t_game *game, char *path, const char *entity);
void		find_sprite(t_game *game, int y, int x);
void		render_sprite(t_game *game, t_image sprite, int line, int column);
void		render_player(t_game *game, int y, int x);

// handle_input.c
int			handle_input(int key, t_game *game);
void		move_player(t_game *game, int new_x, int new_y, int player_sprite);
void		victory(t_game *game);
int			close_game(t_game *game);
void		print_movements(t_game *game);

// free.c
void		free_all(t_game *game);
void		destroy_images(t_game *game);

#endif