/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:56:29 by pafroidu          #+#    #+#             */
/*   Updated: 2025/08/02 10:21:33 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define MAP_ERROR_OPEN -1
# define MAP_ERROR_EMPTY_FILE -2
# define MAP_ERROR_LINE_LEN -3
# define MAP_ERROR_MALLOC -4
# define MAP_ERROR_EMPTY_LIST -5
# define MAP_ERROR_INVALID_CHARACTER -6
# define MAP_ERROR_INVALID_FILENAME -7
# define MAP_ERROR_INVALID_EXTENSION -8
# define MAP_ERROR_WRONG_COLLECTIBLE_NUM -9
# define MAP_ERROR_WRONG_PLAYER_NUM -10
# define MAP_ERROR_WRONG_EXIT_NUM -11
# define MAP_ERROR_WRONG_WALL_CHARACTER -12
# define MAP_ERROR_PLAYER_NOT_FOUND -13
# define MAP_ERROR_ELEMENTS_NOT_ACCESSIBLE -14
# define MAP_ERROR_INVALID_SIZE -15
# define MAP_WALL_COLLISION -16
# define MAP_OUT_OF_LIMITS -17

typedef struct s_map
{
	t_list	*line;
	int		width;
	int		height;
}	t_map;

typedef struct s_elements
{
	int	player;
	int	exit;
	int	collectible;
}	t_elements;

/* main map parser - map line to linked list */
t_map	*full_map_parsing(const char *filename);
int		validate_full_map_content(t_map *map_to_list);
t_map	*extract_map_line_to_list(const char *filename);

/* check map validity : exists ? valid lines len ? */
int		open_map(const char *filename, t_map *map_parsing);
void	close_map(int map_fd);
int		get_line_width(char *current_line);

/* fill parsing structure + append map lines to a linked list */
int		read_map_lines(t_map *map_parsing, int map_fd);
int		append_line_to_list(t_map *map_parsing, char *current_line);
void	fill_line_width(t_map *map_parsing, char *current_line);
void	fill_map_height(t_map *map_parsing);

/* validate map content */
int		validate_all_map_chars(t_map *map_to_list);
int		validate_minimum_size(t_map *map_to_list);
int		validate_map_elements_count(t_map *map_to_list);
int		check_map_file_extension(const char *filename);
void	count_map_elements(t_map *map_to_list, t_elements *map_elements);

/* validate map walls */
int		validate_all_walls(t_map *map_to_list);

/* validate solvable path */
char	**list_to_grid(t_map *map_to_list);
int		find_player_position(char **grid, int *x, int *y, t_map *map);
int		validate_solvable_path(t_map *map_to_list);

/* cleanup */
void	clean_map_structure(t_map *parsed_map);
void	clear_gnl_buffer(int fd);

/* print errors */
void	print_error_msg(char *pre, char *main, char *post);

#endif
