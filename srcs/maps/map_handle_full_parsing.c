/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle_full_parsing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:07:31 by pafroidu          #+#    #+#             */
/*   Updated: 2025/08/03 18:55:45 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	validate_full_map_content - orchestrates all map content validations
	@param map_to_list : parsed map structure to validate
	@return : EXIT_SUCCESS if all validations pass, EXIT_FAILURE otherwise

	Validation Pipeline:
	1. validate_all_map_chars() - only 0,1,C,E,P allowed
	2. validate_minimum_size() - reject map under 3x3 (impossible path)
	3. validate_map_elements_count() - 1P, 1E, ≥1C required
	4. validate_all_walls() - borders must be walls only
	5. validate_solvable_path() - flood fill pathfinding validation
*/
int	validate_full_map_content(t_map *map_to_list)
{
	if (validate_all_map_chars(map_to_list) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (validate_minimum_size(map_to_list) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (validate_map_elements_count(map_to_list) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (validate_all_walls(map_to_list) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (validate_solvable_path(map_to_list) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
	full_map_parsing - main parsing orchestrator handles complete map validation
	@param filename : path to .ber map file
	@return : filled t_map structure if success, NULL if any error

	Workflow:
	1. Check file extension (.ber mandatory)
	2. Extract map lines to linked list structure
	3. Validate all map content through sub-validators
	4. Clean and return NULL if any validation fails
	5. Return complete t_map structure if all OK
*/
t_map	*full_map_parsing(const char *filename)
{
	t_map	*map_to_list;

	if (check_map_file_extension(filename) != EXIT_SUCCESS)
		return (NULL);
	map_to_list = extract_map_line_to_list(filename);
	if (!map_to_list)
		return (NULL);
	if (validate_full_map_content(map_to_list) != EXIT_SUCCESS)
	{
		clean_map_structure(map_to_list);
		return (NULL);
	}
	return (map_to_list);
}
