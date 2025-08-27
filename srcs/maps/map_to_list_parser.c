/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_list_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:08:10 by pafroidu          #+#    #+#             */
/*   Updated: 2025/07/29 11:29:02 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	extract_map_line_to_list - creates t_map structure and extracts map lines
	to linked list
	@param filename : path to .ber file to parse
	@return : allocated and filled t_map structure if success, NULL if error

	Workflow:
	1. Malloc t_map structure on heap
	2. Initialize all fields to 0 (avoid garbage values)
	3. Open file with security checks
	4. Delegate line reading to read_map_lines()
	5. Handle status and cleanup if error
	6. Close file descriptor properly
	7. Fill height field with total line count
*/
t_map	*extract_map_line_to_list(const char *filename)
{
	t_map	*map_parsing;
	int		map_fd;
	int		status;

	map_parsing = malloc(sizeof(t_map));
	if (!map_parsing)
		return (NULL);
	ft_memset(map_parsing, 0, sizeof(t_map));
	map_fd = open_map(filename, map_parsing);
	if (map_fd == MAP_ERROR_OPEN)
		return (NULL);
	status = read_map_lines(map_parsing, map_fd);
	close_map(map_fd);
	if (status != EXIT_SUCCESS)
	{
		free(map_parsing);
		return (NULL);
	}
	fill_map_height(map_parsing);
	return (map_parsing);
}
