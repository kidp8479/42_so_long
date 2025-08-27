/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_load_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:38:11 by pafroidu          #+#    #+#             */
/*   Updated: 2025/08/02 19:35:22 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	ASSETS LOADER MODULE - Individual asset loading functions with validation

	This module contains 5 identical loading functions (load_walls, load_floor,
	load_exit, load_player, load_collectible) that follow the same pattern:

	Standard Workflow for each loader:
	1. Load XPM file from ASSETS_PATH using MLX
	2. Validate file loading success (file exists and readable)
	3. Validate image dimensions (must be exactly TILE_SIZE x TILE_SIZE)
	4. If dimension validation fails: cleanup loaded image and return error
	5. If all validations pass: return EXIT_SUCCESS

	Error Handling:
	- File not found: Print descriptive error with path guidance
	- Wrong dimensions: Print expected size, cleanup image, return failure
	- Consistent error messages for easy debugging

	Security & Memory:
	- Immediate cleanup on dimension validation failure prevents memory leaks
	- NULL pointer assignment after cleanup prevents double-free errors
	- All functions follow identical validation pattern for consistency

	Dependencies: Requires valid MLX pointer and ASSETS_PATH defined
	Usage: Called individually by load_all_assets() with comprehensive error
	handling

	Note: These functions are designed to be atomic - they either succeed
	completely
	or fail cleanly with proper resource cleanup, following RAII-like principles.
*/
int	load_walls(t_game *game_elts)
{
	int	width;
	int	height;

	game_elts->game_assets.wall = mlx_xpm_file_to_image(
			game_elts->mlx_ptr,
			ASSETS_PATH "wall.xpm",
			&width,
			&height);
	if (!game_elts->game_assets.wall)
	{
		print_error_msg("asset:", "failed to load wall.xpm",
			"check file exists in ./assets/ folder");
		return (EXIT_FAILURE);
	}
	if (width != TILE_SIZE || height != TILE_SIZE)
	{
		print_error_msg("asset:", "wall.xpm should be 32x32px",
			"current size does not match TILE_SIZE");
		mlx_destroy_image(game_elts->mlx_ptr,
			game_elts->game_assets.wall);
		game_elts->game_assets.wall = NULL;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	load_floor(t_game *game_elts)
{
	int	width;
	int	height;

	game_elts->game_assets.floor = mlx_xpm_file_to_image(
			game_elts->mlx_ptr,
			ASSETS_PATH "floor.xpm",
			&width,
			&height);
	if (!game_elts->game_assets.floor)
	{
		print_error_msg("asset:", "failed to load floor.xpm",
			"check file exists in ./assets/ folder");
		return (EXIT_FAILURE);
	}
	if (width != TILE_SIZE || height != TILE_SIZE)
	{
		print_error_msg("asset:", "floor.xpm should be 32x32px",
			"current size does not match TILE_SIZE");
		mlx_destroy_image(game_elts->mlx_ptr,
			game_elts->game_assets.floor);
		game_elts->game_assets.floor = NULL;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	load_exit(t_game *game_elts)
{
	int	width;
	int	height;

	game_elts->game_assets.exit = mlx_xpm_file_to_image(
			game_elts->mlx_ptr,
			ASSETS_PATH "exit.xpm",
			&width,
			&height);
	if (!game_elts->game_assets.exit)
	{
		print_error_msg("asset:", "failed to load exit.xpm",
			"check file exists in ./assets/ folder");
		return (EXIT_FAILURE);
	}
	if (width != TILE_SIZE || height != TILE_SIZE)
	{
		print_error_msg("asset:", "exit.xpm should be 32x32px",
			"current size does not match TILE_SIZE");
		mlx_destroy_image(game_elts->mlx_ptr,
			game_elts->game_assets.exit);
		game_elts->game_assets.exit = NULL;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	load_player(t_game *game_elts)
{
	int	width;
	int	height;

	game_elts->game_assets.player = mlx_xpm_file_to_image(
			game_elts->mlx_ptr,
			ASSETS_PATH "player.xpm",
			&width,
			&height);
	if (!game_elts->game_assets.player)
	{
		print_error_msg("asset:", "failed to load player.xpm",
			"check file exists in ./assets/ folder");
		return (EXIT_FAILURE);
	}
	if (width != TILE_SIZE || height != TILE_SIZE)
	{
		print_error_msg("asset:", "player.xpm should be 32x32px",
			"current size does not match TILE_SIZE");
		mlx_destroy_image(game_elts->mlx_ptr,
			game_elts->game_assets.player);
		game_elts->game_assets.player = NULL;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	load_collectible(t_game *game_elts)
{
	int	width;
	int	height;

	game_elts->game_assets.collectible = mlx_xpm_file_to_image(
			game_elts->mlx_ptr,
			ASSETS_PATH "collectible.xpm",
			&width,
			&height);
	if (!game_elts->game_assets.collectible)
	{
		print_error_msg("asset:", "failed to load collectible.xpm",
			"check file exists in ./assets/ folder");
		return (EXIT_FAILURE);
	}
	if (width != TILE_SIZE || height != TILE_SIZE)
	{
		print_error_msg("asset:", "collectible.xpm should be 32x32px",
			"current size does not match TILE_SIZE");
		mlx_destroy_image(game_elts->mlx_ptr,
			game_elts->game_assets.collectible);
		game_elts->game_assets.collectible = NULL;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
