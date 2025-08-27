/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_file_extension.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:53:06 by pafroidu          #+#    #+#             */
/*   Updated: 2025/07/31 11:22:52 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	get_basename - extracts filename from full file path
	@param path : complete file path (ex: "./maps/test.ber")
	@return : pointer to actual filename part (ex: "test.ber")
	
	- Handles all path formats: relative, absolute, nested directories
*/
static const char	*get_basename(const char *path)
{
	const char	*basename;
	int			i;

	basename = path;
	i = 0;
	while (path[i])
	{
		if (path[i] == '/')
			basename = &path[i + 1];
		i++;
	}
	return (basename);
}

/*
	check_map_file_extension - validates .ber extension with complete security
	@param filename : file path to validate (any format supported)
	@return : EXIT_SUCCESS if valid .ber, specific error code otherwise

	Updated Security Pipeline:
	1. NULL pointer protection - prevent segfault
	2. Minimum length validation - reject impossibly short filenames  
	3. Extract actual filename from path - handle ./maps/, /path/, etc.
	4. Hidden file detection - check if actual filename starts with '.'
	5. Extension validation - ensure ends with exactly ".ber"
	6. Specific error messages for debugging and user feedback
*/
int	check_map_file_extension(const char *filename)
{
	int			filename_len;
	const char	*basename;

	if (!filename)
	{
		print_error_msg("map:", "invalid filename", NULL);
		return (MAP_ERROR_EMPTY_FILE);
	}
	filename_len = ft_strlen(filename);
	if (filename_len < 5)
	{
		print_error_msg("map:", "filename too short (min: c.ber)", NULL);
		return (MAP_ERROR_INVALID_FILENAME);
	}
	basename = get_basename(filename);
	if (basename[0] == '.')
	{
		print_error_msg("map:", "hidden .ber files not allowed", NULL);
		return (MAP_ERROR_INVALID_FILENAME);
	}
	if (ft_strncmp(filename + (filename_len - 4), ".ber", 4) == 0)
		return (EXIT_SUCCESS);
	print_error_msg("map:", "the map file should have a .ber extension", NULL);
	return (MAP_ERROR_INVALID_EXTENSION);
}
