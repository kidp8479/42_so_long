/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:36:44 by pafroidu          #+#    #+#             */
/*   Updated: 2025/08/02 10:22:33 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "mlx.h"
# include "render.h"

# define TILE_SIZE 32

# define MLX_ERROR_INITILIALISATION -16
# define MLX_ERROR_GAME_ELEMENTS_DATA -17
# define MLX_ERROR_WINDOWS_CREATION -18

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		*parsed_map;
	int			screen_width;
	int			screen_height;
	int			win_width;
	int			win_height;
	t_assets	game_assets;
	char		**grid;
	int			player_x;
	int			player_y;
	int			move_count;
	int			collectible_left;
	int			game_won;
}	t_game;

/* mlx init */
int		full_game_exec(t_map *parsed_map);

/* screendata */
int		validate_screen_and_map_size(t_game *game_elts);

/* cleanup */
int		clean_and_close_game(t_game *game_elts);

/* gameplay */
int		init_gameplay_data(t_game *game_elts);

/* keys */
int		handle_key_press(int keycode, t_game *game_elts);

/* decoration */
void	print_ascii_art_hello(void);
void	print_ascii_art_bye(void);
void	print_ascii_art_error(void);

#endif
