/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:35:58 by pafroidu          #+#    #+#             */
/*   Updated: 2025/08/04 11:51:55 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	init_game - initializes MLX library and sets up game foundation
	@param game_elts : game structure to initialize with MLX pointer
	@return : EXIT_SUCCESS if MLX init OK, MLX_ERROR_INITILIALISATION if failure

	Security: Validates game_elts pointer before MLX operations
	Sets: game_elts->mlx_ptr with mlx_init() result
*/
static int	init_game(t_game *game_elts)
{
	if (!game_elts)
	{
		print_error_msg("mlx:", "error with some game elements data", NULL);
		return (MLX_ERROR_GAME_ELEMENTS_DATA);
	}
	game_elts->mlx_ptr = mlx_init();
	if (!game_elts->mlx_ptr)
	{
		print_error_msg("mlx:", "game initialisation went wrong", NULL);
		return (MLX_ERROR_INITILIALISATION);
	}
	return (EXIT_SUCCESS);
}

/*
	init_windows - creates game window with dynamic dimensions and title
	@param game_elts : game structure containing MLX ptr and window dimensions
	@return : EXIT_SUCCESS if window created, MLX_ERROR_WINDOWS_CREATION if not

	Requires: game_elts->mlx_ptr, game_elts->win_width, game_elts->win_height
	Sets: game_elts->win_ptr with mlx_new_window() result
*/
static int	init_windows(t_game *game_elts)
{
	if (!game_elts)
	{
		print_error_msg("mlx:", "error with some game elements data", NULL);
		return (MLX_ERROR_GAME_ELEMENTS_DATA);
	}
	game_elts->win_ptr = mlx_new_window(game_elts->mlx_ptr,
			game_elts->win_width,
			game_elts->win_height,
			"SO_LONG - a game about a hungry dino");
	if (!game_elts->win_ptr)
	{
		print_error_msg("mlx:", "windows creation went wrong", "NULL");
		return (MLX_ERROR_WINDOWS_CREATION);
	}
	return (EXIT_SUCCESS);
}

/*
	clean_and_close_game - cleanup and program termination
	@param game_elts : game structure containing all allocated resources
	@return : never returns (calls exit(0))

	Cleanup order:
	1. Assets (textures via cleanup_partial_assets)
	2. Grid array (2D char array)
	3. Parsed map structure (linked list)
	4. MLX window
	5. MLX display and pointer

	Security: Null-checks all pointers before freeing, sets to NULL after clean
	Exit: Always terminates program with exit(0)
*/
int	clean_and_close_game(t_game *game_elts)
{
	if (game_elts && game_elts->mlx_ptr)
		cleanup_partial_assets(game_elts);
	if (game_elts->grid)
	{
		free_array_args(game_elts->grid);
		game_elts->grid = NULL;
	}
	if (game_elts->parsed_map)
	{
		clean_map_structure(game_elts->parsed_map);
		game_elts->parsed_map = NULL;
	}
	if (game_elts->win_ptr)
	{
		mlx_destroy_window(game_elts->mlx_ptr, game_elts->win_ptr);
		game_elts->win_ptr = NULL;
	}
	if (game_elts->mlx_ptr)
	{
		mlx_destroy_display(game_elts->mlx_ptr);
		free(game_elts->mlx_ptr);
		game_elts->mlx_ptr = NULL;
	}
	exit(0);
}

/*
	full_game_exec - complete game execution pipeline from map to playable game
	@param parsed_map : validated map structure from parsing phase
	@return : EXIT_SUCCESS if game runs successfully, EXIT_FAILURE if any step
	fails

	Pipeline:
	1. Initialize game structure and MLX
	2. Validate screen dimensions vs map size
	3. Create game window
	4. Load all XMP textures (5 assets)
	5. Convert map list to 2D grid
	6. Render initial map display
	7. Initialize gameplay data (player position, collectibles count)
	8. Setup event hooks (keyboard + window close)
	9. Start MLX main loop

	Error handling: Calls clean_and_close_game() for any initialization failure
	Hooks: ESC key + window X button for clean exit
*/
int	full_game_exec(t_map *parsed_map)
{
	t_game	game_elts;

	ft_memset(&game_elts, 0, sizeof(t_game));
	game_elts.parsed_map = parsed_map;
	if (init_game(&game_elts) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	validate_screen_and_map_size(&game_elts);
	if (init_windows(&game_elts) != EXIT_SUCCESS)
		clean_and_close_game(&game_elts);
	print_ascii_art_hello();
	if (load_all_assets(&game_elts) != EXIT_SUCCESS)
		clean_and_close_game(&game_elts);
	game_elts.grid = list_to_grid(game_elts.parsed_map);
	if (!game_elts.grid)
	{
		cleanup_partial_assets(&game_elts);
		clean_and_close_game(&game_elts);
	}
	if (init_gameplay_data(&game_elts) != EXIT_SUCCESS)
		clean_and_close_game(&game_elts);
	mapping_assets_to_the_grid(&game_elts);
	mlx_key_hook(game_elts.win_ptr, handle_key_press, &game_elts);
	mlx_hook(game_elts.win_ptr, 17, 0, clean_and_close_game, &game_elts);
	mlx_loop(game_elts.mlx_ptr);
	return (EXIT_SUCCESS);
}
