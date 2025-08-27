/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:00:34 by pafroidu          #+#    #+#             */
/*   Updated: 2025/07/29 12:43:45 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	get_line_width - calculates real width of a line (excluding newline)
	@param current_line : line to measure
	@return : actual character count without '\n'

	Logic: Checks for newline presence and adjusts length accordingly
*/
int	get_line_width(char *current_line)
{
	int	current_line_len;

	if (ft_strchr(current_line, '\n') != NULL)
		current_line_len = ft_strlen(current_line) - 1;
	else
		current_line_len = ft_strlen(current_line);
	return (current_line_len);
}

/*
	fill_line_width - sets reference width from first line
	@param map_parsing : structure to fill
	@param current_line : first line used as width reference

	Usage: Called once on first line to establish width standard
*/
void	fill_line_width(t_map *map_parsing, char *current_line)
{
	map_parsing->width = get_line_width(current_line);
}

/*
	fill_map_height - calculates total map height from linked list size
	@param map_parsing : structure to fill with height

	Logic: Height = number of nodes = number of lines processed
*/
void	fill_map_height(t_map *map_parsing)
{
	map_parsing->height = ft_lstsize(map_parsing->line);
}

/*
	is_valid_line_width - validates current line width against reference
	@param map_parsing : structure containing reference width
	@param current_line_len : width of current line to validate
	@return : EXIT_SUCCESS if match, MAP_ERROR_LINE_LEN if different

	Security: Ensures all lines have same width (rectangular format)
*/
static int	is_valid_line_width(t_map *map_parsing, int current_line_len)
{
	if (current_line_len != map_parsing->width)
	{
		print_error_msg("map:", "the map is not rectangular", NULL);
		return (MAP_ERROR_LINE_LEN);
	}
	return (EXIT_SUCCESS);
}

/*
	append_line_to_list - validates and adds line to linked list
	@param map_parsing : structure to add line to
	@param current_line : line to validate and add
	@return : EXIT_SUCCESS if OK, error code if validation/malloc fails

	Workflow:
	1. Calculate current line width
	2. Validate against reference width (rectangular check)
	3. Create new list node with line content
	4. Append to end of linked list
*/
int	append_line_to_list(t_map *map_parsing, char *current_line)
{
	int		current_line_len;
	t_list	*new_node;

	current_line_len = get_line_width(current_line);
	if (is_valid_line_width(map_parsing, current_line_len) != EXIT_SUCCESS)
		return (MAP_ERROR_LINE_LEN);
	new_node = ft_lstnew(current_line);
	if (!new_node)
		return (MAP_ERROR_MALLOC);
	ft_lstadd_back(&map_parsing->line, new_node);
	return (EXIT_SUCCESS);
}
