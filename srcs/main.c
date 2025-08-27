/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:32:32 by pafroidu          #+#    #+#             */
/*   Updated: 2025/08/02 11:25:23 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	main - entry point of so_long game with complete lifecycle management
	@param argc : argument count (must be exactly 2)
	@param argv : argument vector [program_name, map_file.ber]
	@return : EXIT_SUCCESS if game completed normally, EXIT_FAILURE on error

	Program Lifecycle:
	1. Validate command line arguments (exactly one map file required)
	2. Parse and validate map file using full parsing pipeline
	3. Execute complete game loop with MLX and user interaction
	4. Clean up map structure memory before exit

	Error Handling:
	- Wrong argument count: Display usage and exit
	- Map parsing failure: Error handled by parsing functions, early return
	- Game execution: Handled internally by full_game_exec()

	Memory Management: Ensures map structure cleanup regardless of exit path
	Usage: ./so_long maps/valid_map.ber
*/
int	main(int argc, char **argv)
{
	t_map	*parsed_map;

	if (argc != 2)
	{
		print_error_msg("expected:", "./so_long map_name.ber", NULL);
		return (EXIT_FAILURE);
	}
	parsed_map = full_map_parsing(argv[1]);
	if (!parsed_map)
		return (EXIT_FAILURE);
	full_game_exec(parsed_map);
	clean_map_structure(parsed_map);
	return (EXIT_SUCCESS);
}
