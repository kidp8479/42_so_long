/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_list_reader.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:09:12 by pafroidu          #+#    #+#             */
/*   Updated: 2025/08/03 18:49:13 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	open_map - secure wrapper for file opening with error handling
	@param filename : path to file to open
	@param map_parsing : structure to free if open fails
	@return : file descriptor if success, MAP_ERROR_OPEN if failure

	Security: Frees structure immediately if open fails to prevent leaks
*/
int	open_map(const char *filename, t_map *map_parsing)
{
	int	map_fd;

	map_fd = open(filename, O_RDONLY);
	if (map_fd == MAP_ERROR_OPEN)
	{
		print_error_msg(NULL, NULL, NULL);
		perror("open");
		free(map_parsing);
		return (MAP_ERROR_OPEN);
	}
	return (map_fd);
}

/*
	close_map - secure wrapper for file closing with fd validation
	@param map_fd : file descriptor to close

	Security: Only closes valid file descriptors (>= 0)
*/
void	close_map(int map_fd)
{
	if (map_fd >= 0)
		close(map_fd);
}

/*
	handle_empty_map - checks for empty/unreadable files on first read
	@param current_line : first line read from get_next_line
	@param map_fd : file descriptor to clean up
	@return : EXIT_SUCCESS if line exists, MAP_ERROR_EMPTY_FILE otherwise

	Cleanup: Clears GNL buffer and closes fd if file empty
*/
static int	handle_empty_map(char *current_line, int map_fd)
{
	if (!current_line)
	{
		print_error_msg("map:", "empty map or unreadable file", NULL);
		clear_gnl_buffer(map_fd);
		close_map(map_fd);
		return (MAP_ERROR_EMPTY_FILE);
	}
	return (EXIT_SUCCESS);
}

/*
	add_and_check_map_line - adds line to list with error handling
	@param map_parsing : map structure to add line to
	@param current_line : line to add and validate
	@return : EXIT_SUCCESS if OK, error code if validation fails

	Cleanup: Frees entire list and current line if append fails
*/
static int	add_and_check_map_line(t_map *map_parsing, char *current_line)
{
	int	status;

	status = append_line_to_list(map_parsing, current_line);
	if (status != EXIT_SUCCESS)
	{
		ft_lstclear(&map_parsing->line, free);
		free(current_line);
	}
	return (status);
}

/*
	read_map_lines - main reading function, processes entire file line by line
	@param map_parsing : structure to fill with map data
	@param map_fd : opened file descriptor
	@return : EXIT_SUCCESS if all OK, error code if any problem

	Workflow:
	1. Read first line and check if file empty
	2. Use first line to set reference width
	3. Process first line (add to list)
	4. Continue reading and processing remaining lines
	5. Clean GNL buffer if any error occurs
*/
int	read_map_lines(t_map *map_parsing, int map_fd)
{
	char	*line;
	int		status;

	line = get_next_line(map_fd);
	if (handle_empty_map(line, map_fd) != EXIT_SUCCESS)
		return (MAP_ERROR_EMPTY_FILE);
	fill_line_width(map_parsing, line);
	status = add_and_check_map_line(map_parsing, line);
	if (status != EXIT_SUCCESS)
	{
		clear_gnl_buffer(map_fd);
		return (status);
	}
	line = get_next_line(map_fd);
	while (line)
	{
		status = add_and_check_map_line(map_parsing, line);
		if (status != EXIT_SUCCESS)
		{
			clear_gnl_buffer(map_fd);
			return (status);
		}
		line = get_next_line(map_fd);
	}
	return (EXIT_SUCCESS);
}
