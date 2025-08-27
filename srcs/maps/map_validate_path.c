/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:10:15 by pafroidu          #+#    #+#             */
/*   Updated: 2025/07/31 18:27:31 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	find_player_position - locates player 'P' position in 2D grid
	@param grid : 2D array to search in
	@param x : pointer to store player x coordinate
	@param y : pointer to store player y coordinate
	@param map : map structure for dimensions
	@return : EXIT_SUCCESS if found, EXIT_FAILURE if not found

	Process: Double loop through grid, returns coordinates by reference
*/
int	find_player_position(char **grid, int *x, int *y, t_map *map)
{
	int	y_position;
	int	x_position;

	y_position = 0;
	while (y_position < map->height)
	{
		x_position = 0;
		while (x_position < map->width)
		{
			if (grid[y_position][x_position] == 'P')
			{
				*y = y_position;
				*x = x_position;
				return (EXIT_SUCCESS);
			}
			x_position++;
		}
		y_position++;
	}
	return (EXIT_FAILURE);
}

/*
	flood_fill - recursive flood fill algorithm to mark accessible areas
	@param grid : 2D array to process (modified in place)
	@param x : current x coordinate
	@param y : current y coordinate
	@param map : map structure for boundary checking
	@return : EXIT_SUCCESS (always, used for recursion)

	Logic: Marks walkable cells ('0', 'C', 'E') as visited ('X')
	Recursion: Explores 4 directions (right, left, down, up)
*/
static int	flood_fill(char **grid, int x, int y, t_map *map)
{
	if (x < 0 || y < 0 || map->width <= x || map->height <= y)
		return (EXIT_FAILURE);
	if (grid[y][x] != '0' && grid[y][x] != 'C' && grid[y][x] != 'E')
		return (EXIT_FAILURE);
	if (grid[y][x] == 'X')
		return (EXIT_FAILURE);
	grid[y][x] = 'X';
	flood_fill(grid, x + 1, y, map);
	flood_fill(grid, x - 1, y, map);
	flood_fill(grid, x, y + 1, map);
	flood_fill(grid, x, y - 1, map);
	return (EXIT_SUCCESS);
}

/*
	check_elements_access - verifies all collectibles and exit are accessible
	@param grid : 2D array after flood fill (contains 'X' for visited areas)
	@param map : map structure for dimensions
	@return : EXIT_SUCCESS if all accessible, EXIT_FAILURE if some unreachable

	Logic: Checks if any 'C' or 'E' remain unmarked (not visited by flood fill)
*/
static int	check_elements_access(char **grid, t_map *map)
{
	int	y_position;
	int	x_position;

	y_position = 0;
	while (y_position < map->height)
	{
		x_position = 0;
		while (x_position < map->width)
		{
			if (grid[y_position][x_position] == 'C'
			|| grid[y_position][x_position] == 'E')
				return (EXIT_FAILURE);
			x_position++;
		}
		y_position++;
	}
	return (EXIT_SUCCESS);
}

/*
	perform_all_path_checks - orchestrates complete pathfinding validation
	@param grid : 2D array to analyze
	@param map_to_list : map structure for context
	@return : EXIT_SUCCESS if solvable, specific error code otherwise

	Workflow:
	1. Find player position in grid
	2. Replace player 'P' with '0' (walkable)
	3. Execute flood fill from player position
	4. Verify all collectibles and exit are accessible
*/
static int	perform_all_path_checks(char **grid, t_map *map_to_list)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (find_player_position(grid, &x, &y, map_to_list) != EXIT_SUCCESS)
	{
		print_error_msg("map:", "player position not found", NULL);
		return (MAP_ERROR_PLAYER_NOT_FOUND);
	}
	grid[y][x] = '0';
	if (flood_fill(grid, x, y, map_to_list) != EXIT_SUCCESS)
	{
		print_error_msg("map:", "no valid path to complete the map", NULL);
		return (MAP_ERROR_ELEMENTS_NOT_ACCESSIBLE);
	}
	if (check_elements_access(grid, map_to_list) != EXIT_SUCCESS)
	{
		print_error_msg("map:", "exit or collectibles not accessible", NULL);
		return (MAP_ERROR_ELEMENTS_NOT_ACCESSIBLE);
	}
	return (EXIT_SUCCESS);
}

/*
	validate_solvable_path - validates that map has solvable path to all objects
	@param map_to_list : map structure to validate
	@return : EXIT_SUCCESS if solvable, error code if unsolvable

	Process: Converts to grid, performs pathfinding, cleans up
	Guarantees: Player can reach all collectibles and exit
*/
int	validate_solvable_path(t_map *map_to_list)
{
	char		**grid;
	int			status;

	grid = list_to_grid(map_to_list);
	if (!grid)
		return (EXIT_FAILURE);
	status = perform_all_path_checks(grid, map_to_list);
	free_array_args(grid);
	return (status);
}
