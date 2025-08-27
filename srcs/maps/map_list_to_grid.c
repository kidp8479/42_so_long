/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list_to_grid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:56:46 by pafroidu          #+#    #+#             */
/*   Updated: 2025/07/29 12:11:03 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	list_to_grid - converts linked list map structure to 2D array for gameplay
	@param map_to_list : source map structure with linked list
	@return : allocated 2D char array if success, NULL if error

	Process: Allocates array of strings, duplicates each line from linked list
*/
char	**list_to_grid(t_map *map_to_list)
{
	int		i;
	char	**map_to_tab;
	t_list	*current;
	char	*line;

	if (!map_to_list || !map_to_list->line)
		return (NULL);
	map_to_tab = malloc(sizeof(char *) * (map_to_list->height + 1));
	if (!map_to_tab)
		return (NULL);
	i = 0;
	current = map_to_list->line;
	while (current && i < map_to_list->height)
	{
		line = (char *)current->content;
		map_to_tab[i] = ft_strdup(line);
		if (!map_to_tab[i])
			return (free_array_args(map_to_tab), NULL);
		current = current->next;
		i++;
	}
	map_to_tab[i] = NULL;
	return (map_to_tab);
}
