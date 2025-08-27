/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mapping_to_the_grid.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:12:05 by pafroidu          #+#    #+#             */
/*   Updated: 2025/08/04 12:32:26 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	put_tile - safely renders an asset at specified grid coordinates
	@param game_elts : game structure containing MLX pointers
	@param asset : MLX image asset to render
	@param x : grid X coordinate (will be multiplied by TILE_SIZE)
	@param y : grid Y coordinate (will be multiplied by TILE_SIZE)

	Logic: Converts grid coordinates to pixel coordinates using TILE_SIZE
	Security: Validates all pointers before MLX call to prevent segfaults
	Usage: Helper function called by render_tile_at_position()
*/
static void	put_tile(t_game *game_elts, void *asset, int x, int y)
{
	if (!game_elts || !game_elts->mlx_ptr || !game_elts->win_ptr || !asset)
		return ;
	mlx_put_image_to_window(game_elts->mlx_ptr, game_elts->win_ptr,
		asset, x * TILE_SIZE, y * TILE_SIZE);
}

/*
	validate_mapping_requirements - validates all prerequisites for rendering
	@param game_elts : game structure to validate
	@return : EXIT_SUCCESS if all valid, EXIT_FAILURE if missing elements

	Validation Checks:
	1. Game structure, grid and parsed map exist
	2. All 5 required assets are loaded (wall, floor, player, exit, collectible)

	Security: Prevents rendering attempts with incomplete data
	Usage: Called once at start of mapping_assets_to_the_grid()
*/
static int	validate_mapping_requirements(t_game *game_elts)
{
	if (!game_elts || !game_elts->grid || !game_elts->parsed_map)
	{
		print_error_msg("render:", "invalid game elements", NULL);
		return (EXIT_FAILURE);
	}
	if (!game_elts->game_assets.wall || !game_elts->game_assets.floor
		|| !game_elts->game_assets.player || !game_elts->game_assets.exit
		|| !game_elts->game_assets.collectible)
	{
		print_error_msg("render:", "assets not loaded", NULL);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
	render_tile_at_position - renders appropriate assets for a single grid
	position
	@param game_elts : game structure containing all game data
	@param x : grid X coordinate to render
	@param y : grid Y coordinate to render

	Rendering Logic:
	1.	Always render floor as base layer
	2.	If position matches player location:
		- Render exit/collectible underneath if present
		- Render player on top (visual priority)
	3.	If position doesn't match player:
		- Render tile content normally (wall, exit, collectible)

	Visual Priority: Player always rendered on top when at same position
	Usage: Called for each grid cell during full map rendering
*/
static void	render_tile_at_position(t_game *game_elts, int x, int y)
{
	char	tile;

	tile = game_elts->grid[y][x];
	put_tile(game_elts, game_elts->game_assets.floor, x, y);
	if (x == game_elts->player_x && y == game_elts->player_y)
	{
		if (tile == 'E')
			put_tile(game_elts, game_elts->game_assets.exit, x, y);
		else if (tile == 'C')
			put_tile(game_elts, game_elts->game_assets.collectible, x, y);
		put_tile(game_elts, game_elts->game_assets.player, x, y);
	}
	else
	{
		if (tile == '1')
			put_tile(game_elts, game_elts->game_assets.wall, x, y);
		else if (tile == 'E')
			put_tile(game_elts, game_elts->game_assets.exit, x, y);
		else if (tile == 'P')
			put_tile(game_elts, game_elts->game_assets.player, x, y);
		else if (tile == 'C')
			put_tile(game_elts, game_elts->game_assets.collectible, x, y);
	}
}

/*
	mapping_assets_to_the_grid - main rendering function for entire game map
	@param game_elts : game structure containing all rendering data
	@return : EXIT_SUCCESS if rendering completed, EXIT_FAILURE if validation
	fails

	Workflow:
	1. Validate all rendering requirements (assets, structures)
	2. Iterate through entire map grid (height x width)
	3. Render each position using render_tile_at_position()

	Performance: Full map re-render on each call
	Usage: Called after player movement or window events to refresh display
	Dependencies: Requires loaded assets and valid grid conversion
*/
int	mapping_assets_to_the_grid(t_game *game_elts)
{
	int	y;
	int	x;

	if (validate_mapping_requirements(game_elts) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	y = 0;
	while (y < game_elts->parsed_map->height)
	{
		x = 0;
		while (x < game_elts->parsed_map->width)
		{
			render_tile_at_position(game_elts, x, y);
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}
