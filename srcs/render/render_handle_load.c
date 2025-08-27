/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_handle_load.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:42:48 by pafroidu          #+#    #+#             */
/*   Updated: 2025/08/02 19:34:52 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	cleanup_wall_floor - destroys wall and floor image assets from MLX
	@param game_elts : game structure containing assets to clean

	Logic: Safely destroys MLX images and sets pointers to NULL
	Security: Checks asset existence before destruction to prevent errors
	Memory: Prevents MLX image memory leaks
*/
static void	cleanup_wall_floor(t_game *game_elts)
{
	if (game_elts->game_assets.wall)
	{
		mlx_destroy_image(game_elts->mlx_ptr, game_elts->game_assets.wall);
		game_elts->game_assets.wall = NULL;
	}
	if (game_elts->game_assets.floor)
	{
		mlx_destroy_image(game_elts->mlx_ptr, game_elts->game_assets.floor);
		game_elts->game_assets.floor = NULL;
	}
}

/*
	cleanup_player_collectible_exit - destroys player, collectible and
	exit assets
	@param game_elts : game structure containing assets to clean

	Logic: Safely destroys MLX images and sets pointers to NULL
	Security: Checks asset existence before destruction to prevent errors
	Memory: Prevents MLX image memory leaks for game entity assets
*/
static void	cleanup_player_collectible_exit(t_game *game_elts)
{
	if (game_elts->game_assets.player)
	{
		mlx_destroy_image(game_elts->mlx_ptr, game_elts->game_assets.player);
		game_elts->game_assets.player = NULL;
	}
	if (game_elts->game_assets.collectible)
	{
		mlx_destroy_image(game_elts->mlx_ptr,
			game_elts->game_assets.collectible);
		game_elts->game_assets.collectible = NULL;
	}
	if (game_elts->game_assets.exit)
	{
		mlx_destroy_image(game_elts->mlx_ptr, game_elts->game_assets.exit);
		game_elts->game_assets.exit = NULL;
	}
}

/*
	cleanup_partial_assets - main cleanup function for all game assets
	@param game_elts : game structure containing all assets to clean

	Workflow:
	1. Validate game structure integrity
	2. Clean wall and floor assets
	3. Clean player, collectible and exit assets

	Usage: Called on asset loading failure or game cleanup
	Security: NULL check prevents segmentation faults
	Memory: Ensures complete asset cleanup to prevent leaks
*/
void	cleanup_partial_assets(t_game *game_elts)
{
	if (!game_elts)
		return ;
	cleanup_wall_floor(game_elts);
	cleanup_player_collectible_exit(game_elts);
}

/*
	load_all_assets - loads all game assets with comprehensive error handling
	@param game_elts : game structure to fill with loaded assets
	@return : EXIT_SUCCESS if all assets loaded, EXIT_FAILURE on any error

	Workflow:
	1. Load walls (if fails, cleanup and return error)
	2. Load floor (if fails, cleanup and return error)
	3. Load exit (if fails, cleanup and return error)
	4. Load player (if fails, cleanup and return error)
	5. Load collectible (if fails, cleanup and return error)

	Error Handling: Any failure triggers complete cleanup of loaded assets
	Memory Safety: Prevents partial asset states that could cause leaks
	Usage: Called once during game initialization after MLX setup
*/
int	load_all_assets(t_game *game_elts)
{
	if (load_walls(game_elts) != EXIT_SUCCESS)
		return (cleanup_partial_assets(game_elts), EXIT_FAILURE);
	if (load_floor(game_elts) != EXIT_SUCCESS)
		return (cleanup_partial_assets(game_elts), EXIT_FAILURE);
	if (load_exit(game_elts) != EXIT_SUCCESS)
		return (cleanup_partial_assets(game_elts), EXIT_FAILURE);
	if (load_player(game_elts) != EXIT_SUCCESS)
		return (cleanup_partial_assets(game_elts), EXIT_FAILURE);
	if (load_collectible(game_elts) != EXIT_SUCCESS)
		return (cleanup_partial_assets(game_elts), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
