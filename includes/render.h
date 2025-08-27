/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:33:01 by pafroidu          #+#    #+#             */
/*   Updated: 2025/08/02 10:22:59 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

typedef struct s_game	t_game;

# define ASSETS_PATH "./assets/"

typedef struct s_assets
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
}	t_assets;

/* load and display assets */
int		load_walls(t_game *game_elts);
int		load_floor(t_game *game_elts);
int		load_exit(t_game *game_elts);
int		load_player(t_game *game_elts);
int		load_all_assets(t_game *game_elts);
int		load_collectible(t_game *game_elts);
int		mapping_assets_to_the_grid(t_game *game_elts);

/* cleanup */
void	cleanup_partial_assets(t_game *game_elts);

#endif
