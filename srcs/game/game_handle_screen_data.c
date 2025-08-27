/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handle_screen_data.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:00:13 by pafroidu          #+#    #+#             */
/*   Updated: 2025/08/02 19:34:21 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	get_screen_size - retrieves current screen dimensions from MLX
	@param game_elts : game structure to fill with screen dimensions

	Logic: Uses MLX function to get screen size and stores in game structure
	Usage: Called once during initialization to determine display limits
*/
static void	get_screen_size(t_game *game_elts)
{
	int	screen_width;
	int	screen_height;

	mlx_get_screen_size(game_elts->mlx_ptr, &screen_width, &screen_height);
	game_elts->screen_width = screen_width;
	game_elts->screen_height = screen_height;
}

/*
	calculate_window_size - calculates required window size and
	validates against screen
	@param game_elts : game structure containing map data and screen info

	Workflow:
	1. Calculate required window size based on map dimensions
	2. Set safety limits to 95% of screen size
	3. Validate if map fits within safe display area
	4. Exit with error if map too large for screen

	Security: Prevents window creation larger than screen capacity
	Cleanup: Calls clean_and_close_game() if size validation fails
*/
static void	calculate_window_size(t_game *game_elts)
{
	int	max_width;
	int	max_height;

	game_elts->win_width = game_elts->parsed_map->width * TILE_SIZE;
	game_elts->win_height = game_elts->parsed_map->height * TILE_SIZE;
	max_width = game_elts->screen_width * 0.95;
	max_height = game_elts->screen_height * 0.95;
	if (game_elts->win_width > max_width || game_elts->win_height > max_height)
	{
		print_error_msg("map:", "too large for this screen", NULL);
		ft_printf("map: size %dx%d exceeds 95%% safe screen limit\n",
			game_elts->win_width, game_elts->win_height);
		ft_printf("please use a smaller map to run the game smoothly :)\n\n");
		print_ascii_art_error();
		clean_and_close_game(game_elts);
	}
}

/*
	validate_screen_and_map_size - main validation function for display
	compatibility
	@param game_elts : game structure containing map and display data
	@return : EXIT_SUCCESS if validation passes

	Workflow:
	1. Get current screen dimensions
	2. Calculate and validate window size requirements
	3. Ensure map can be displayed safely on current screen

	Usage: Called during game initialization before window creation
*/
int	validate_screen_and_map_size(t_game *game_elts)
{
	get_screen_size(game_elts);
	calculate_window_size(game_elts);
	return (EXIT_SUCCESS);
}
