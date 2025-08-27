/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_map_structure.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 23:49:24 by pafroidu          #+#    #+#             */
/*   Updated: 2025/08/04 11:51:09 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	clean_map_structure - frees entire map structure and its linked list content
	@param parsed_map : map structure to clean up

	Process: Frees linked list with content, then frees structure itself
	Safety: Checks for NULL pointer before operations
*/
void	clean_map_structure(t_map *parsed_map)
{
	if (!parsed_map)
		return ;
	if (parsed_map->line)
		ft_lstclear(&parsed_map->line, free);
	free(parsed_map);
}

/*
	clear_gnl_buffer - clears get_next_line internal static buffer
	@param fd : file descriptor to clear buffer for

	Purpose: Prevents memory leaks when stopping GNL reading midfile
	Process: Continues reading until EOF, freeing each line
*/
void	clear_gnl_buffer(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}
