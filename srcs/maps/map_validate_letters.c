/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_letters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:07:03 by pafroidu          #+#    #+#             */
/*   Updated: 2025/07/31 18:54:04 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	is_map_line_valid_chars - validates that line contains only allowed chars
	@param current_line : line to validate character by character
	@return : EXIT_SUCCESS if all chars valid, or MAP_ERROR_INVALID_CHARACTER

	Allowed chars: '0' (empty), '1' (wall), 'C' (collectible),
	'E' (exit), 'P' (player)
*/
static int	is_map_line_valid_chars(char *current_line)
{
	int	i;
	int	current_line_len;

	i = 0;
	current_line_len = get_line_width(current_line);
	while (i < current_line_len)
	{
		if (!(current_line[i] == '0' || current_line[i] == '1'
				|| current_line[i] == 'C' || current_line[i] == 'E'
				|| current_line[i] == 'P'))
			return (MAP_ERROR_INVALID_CHARACTER);
		i++;
	}
	return (EXIT_SUCCESS);
}

/*
	validate_all_map_chars - validates characters across entire map structure
	@param map_to_list : complete map structure to validate
	@return : EXIT_SUCCESS if all lines valid, error code otherwise

	Process: Iterates through linked list, validates each line individually
*/
int	validate_all_map_chars(t_map *map_to_list)
{
	t_list	*current;
	char	*map_line;

	if (!map_to_list || !map_to_list->line)
	{
		print_error_msg("map:", "invalid argument list", NULL);
		return (MAP_ERROR_EMPTY_LIST);
	}
	current = map_to_list->line;
	while (current)
	{
		map_line = (char *)current->content;
		if (is_map_line_valid_chars(map_line) != EXIT_SUCCESS)
		{
			print_error_msg("map:", "invalid character, allowed: 01CEP", NULL);
			return (MAP_ERROR_INVALID_CHARACTER);
		}
		current = current->next;
	}
	return (EXIT_SUCCESS);
}

/*
	count_map_elements - counts occurrences of each game element in map
	@param map_to_list : map structure to analyze
	@param map_elements : structure to fill with counts

	Elements counted: 'P' (player), 'E' (exit), 'C' (collectibles)
	Process: Double loop through lines and characters
*/
void	count_map_elements(t_map *map_to_list, t_elements *map_elements)
{
	t_list	*current;
	char	*map_line;
	int		i;
	int		map_line_len;

	i = 0;
	current = map_to_list->line;
	while (current)
	{
		map_line = (char *)current->content;
		map_line_len = get_line_width(map_line);
		i = 0;
		while (i < map_line_len)
		{
			if (map_line[i] == 'C')
				map_elements->collectible += 1;
			else if (map_line[i] == 'E')
				map_elements->exit += 1;
			else if (map_line[i] == 'P')
				map_elements->player += 1;
			i++;
		}
		current = current->next;
	}
}

/*
	validate_map_elements_count - validates required quantities of game elements
	@param map_to_list : map structure to validate
	@return : EXIT_SUCCESS if quantities correct, specific error code otherwise

	Requirements: exactly 1 exit, exactly 1 player, at least 1 collectible
	Order: Exit → Player → Collectibles (logical priority)
*/
int	validate_map_elements_count(t_map *map_to_list)
{
	t_elements	map_elements;

	ft_memset(&map_elements, 0, sizeof(t_elements));
	count_map_elements(map_to_list, &map_elements);
	if (map_elements.exit != 1)
	{
		print_error_msg("map:", "(only) one exit expected", NULL);
		return (MAP_ERROR_WRONG_EXIT_NUM);
	}
	if (map_elements.player != 1)
	{
		print_error_msg("map:", "(only) one player expected", NULL);
		return (MAP_ERROR_WRONG_PLAYER_NUM);
	}
	if (map_elements.collectible < 1)
	{
		print_error_msg("map:", "at least one collectible expected", NULL);
		return (MAP_ERROR_WRONG_COLLECTIBLE_NUM);
	}
	return (EXIT_SUCCESS);
}
