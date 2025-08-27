/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handle_gameplay.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:33:32 by pafroidu          #+#    #+#             */
/*   Updated: 2025/08/04 12:15:17 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	init_gameplay_data - initializes all gameplay related data and counters
	@param game_elts : game structure to initialize with gameplay data
	@return : EXIT_SUCCESS if initialization completed, EXIT_FAILURE if error

	Workflow:
	1. Initialize temporary elements structure for counting
	2. Validate game structure integrity
	3. Find and set player starting position on grid
	4. Count collectibles on map for victory condition
	5. Initialize game counters (moves, collectibles, victory status)

	Dependencies: Requires valid parsed map and grid conversion
	Security: Validates player position found before proceeding
	Usage: Called once during game initialization after map parsing
*/
int	init_gameplay_data(t_game *game_elts)
{
	t_elements	elements_on_map;

	ft_memset(&elements_on_map, 0, sizeof(t_elements));
	if (!game_elts)
		return (EXIT_FAILURE);
	if (find_player_position(game_elts->grid, &game_elts->player_x,
			&game_elts->player_y, game_elts->parsed_map) != EXIT_SUCCESS)
	{
		ft_printf("assets:", "player position not found", NULL);
		return (EXIT_FAILURE);
	}
	game_elts->grid[game_elts->player_y][game_elts->player_x] = '0';
	count_map_elements(game_elts->parsed_map, &elements_on_map);
	if (elements_on_map.collectible == 0)
		ft_printf("assets:", "could not count the collectibles", NULL);
	game_elts->collectible_left = elements_on_map.collectible;
	game_elts->move_count = 0;
	game_elts->game_won = 0;
	return (EXIT_SUCCESS);
}
