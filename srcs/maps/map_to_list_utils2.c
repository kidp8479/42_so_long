/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_list_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:27:29 by pafroidu          #+#    #+#             */
/*   Updated: 2025/08/03 19:03:59 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	validate_minimum_size - validates map has minimum playable size
	@param map_parsing : map structure to validate
	@return : EXIT_SUCCESS if size OK, MAP_ERROR_INVALID_SIZE otherwise

	Logic: Map must be at least 3x3 to contain walls + player + collectible
	+ exit
*/
int	validate_minimum_size(t_map *map_to_list)
{
	if (!map_to_list)
		return (MAP_ERROR_EMPTY_LIST);
	if (map_to_list->width < 3 || map_to_list->height < 3)
	{
		print_error_msg("map:", "minimum playable map size is 3x3", NULL);
		return (MAP_ERROR_INVALID_SIZE);
	}
	return (EXIT_SUCCESS);
}
