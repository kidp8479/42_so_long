/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:52:45 by pafroidu          #+#    #+#             */
/*   Updated: 2025/07/29 12:44:16 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	validate_top_wall - validates that top border is entirely made of walls
	@param map_to_list : map structure to validate
	@return : EXIT_SUCCESS if all top chars are '1', error code otherwise

	Process: Checks first line of linked list, validates each character is '1'
*/
static int	validate_top_wall(t_map *map_to_list)
{
	int		i;
	char	*line;

	if (!map_to_list || !map_to_list->line)
		return (MAP_ERROR_EMPTY_LIST);
	i = 0;
	line = (char *)map_to_list->line->content;
	while (i < map_to_list->width)
	{
		if (line[i] != '1')
		{
			print_error_msg("map:", "borders must be walls only", NULL);
			return (MAP_ERROR_WRONG_WALL_CHARACTER);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

/*
	validate_bottom_wall - validates that bottom border is made of walls
	@param map_to_list : map structure to validate
	@return : EXIT_SUCCESS if all bottom chars are '1', error code otherwise

	Process: Uses ft_lstlast to get last line, validates each character is '1'
*/
static int	validate_bottom_wall(t_map *map_to_list)
{
	int		i;
	char	*line;
	t_list	*last_line;

	if (!map_to_list || !map_to_list->line)
		return (MAP_ERROR_EMPTY_LIST);
	i = 0;
	last_line = ft_lstlast(map_to_list->line);
	line = (char *)last_line->content;
	while (i < map_to_list->width)
	{
		if (line[i] != '1')
		{
			print_error_msg("map:", "borders must be walls only", NULL);
			return (MAP_ERROR_WRONG_WALL_CHARACTER);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

/*
	validate_side_walls - validates that left and right borders are walls
	@param map_to_list : map structure to validate
	@return : EXIT_SUCCESS if all side chars are '1', error code otherwise

	Process: Iterates through all lines, checks first and last character of each
	Validates: line[0] == '1' and line[width-1] == '1' for every line
*/
static int	validate_side_walls(t_map *map_to_list)
{
	t_list	*current;
	char	*line;

	if (!map_to_list || !map_to_list->line)
		return (MAP_ERROR_EMPTY_LIST);
	current = map_to_list->line;
	while (current)
	{
		line = (char *)current->content;
		if (line[0] != '1')
		{
			print_error_msg("map:", "borders must be walls only", NULL);
			return (MAP_ERROR_WRONG_WALL_CHARACTER);
		}
		if (line[map_to_list->width - 1] != '1')
		{
			print_error_msg("map:", "borders must be walls only", NULL);
			return (MAP_ERROR_WRONG_WALL_CHARACTER);
		}
		current = current->next;
	}
	return (EXIT_SUCCESS);
}

/*
	validate_all_walls - orchestrates validation of all four borders
	@param map_to_list : map structure to validate
	@return : EXIT_SUCCESS if all borders valid, EXIT_FAILURE otherwise

	Order: Top → Sides → Bottom (logical validation sequence)
	Fail-fast: Returns immediately on first border validation failure
*/
int	validate_all_walls(t_map *map_to_list)
{
	if (validate_top_wall(map_to_list) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (validate_side_walls(map_to_list) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (validate_bottom_wall(map_to_list) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
