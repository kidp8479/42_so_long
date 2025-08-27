/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handle_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:59:40 by pafroidu          #+#    #+#             */
/*   Updated: 2025/08/04 13:50:31 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	validate_move - checks if player movement is valid within game boundaries
	@param game_elts : game structure containing map and grid data
	@param new_x : target X coordinate to validate
	@param new_y : target Y coordinate to validate
	@return : EXIT_SUCCESS if valid, MAP_OUT_OF_LIMITS or MAP_WALL_COLLISION
	if invalid

	Logic: Validates movement against map boundaries and wall collisions
	Security: Prevents out-of-bounds access and illegal moves
*/
static int	validate_move(t_game *game_elts, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game_elts->parsed_map->width
		|| new_y < 0 || new_y >= game_elts->parsed_map->height)
		return (MAP_OUT_OF_LIMITS);
	if (game_elts->grid[new_y][new_x] == '1')
		return (MAP_WALL_COLLISION);
	return (EXIT_SUCCESS);
}

/*
	handle_game_logic - processes game events based on target cell content
	@param game_elts : game structure containing game state
	@param target_cell : character at destination position

	Workflow:
	1. Handle collectible pickup (decrease counter, display message)
	2. Handle exit interaction (check win condition, display result)
	3. Exit game if victory achieved, otherwise continue play

	Game Logic: Victory requires all collectibles collected before exit
	Cleanup: Calls clean_and_close_game() on victory condition
*/
static void	handle_game_logic(t_game *game_elts, char target_cell)
{
	if (target_cell == 'C')
	{
		game_elts->collectible_left--;
		ft_printf("collectible found! %d 🍗 remaining before exiting\n",
			game_elts->collectible_left);
	}
	else if (target_cell == 'E')
	{
		if (game_elts->collectible_left == 0)
		{
			game_elts->move_count++;
			ft_printf("YOU WON! game completed in %d moves!\n",
				game_elts->move_count);
			print_ascii_art_bye();
			clean_and_close_game(game_elts);
		}
		else
			ft_printf("exit found but %d 🍗 collectibles remaining!\n",
				game_elts->collectible_left);
	}
}

/*
	update_grid_and_render - updates game grid and refreshes display
	@param game_elts : game structure containing all game data
	@param old_x : previous player X position
	@param old_y : previous player Y position
	@param target_cell : character at new position

	Workflow:
	1. Clear old player position (set to '0')
	2. Update new player position (set to 'P' if not exit)
	3. Clear and re-render entire window
	4. Increment and display move counter

	Performance: Full window refresh ensures visual consistency
*/
static void	update_grid_and_render(t_game *game_elts, int old_x, int old_y,
	char target_cell)
{
	if (game_elts->grid[old_y][old_x] == 'P')
		game_elts->grid[old_y][old_x] = '0';
	if (target_cell != 'E')
		game_elts->grid[game_elts->player_y][game_elts->player_x] = 'P';
	// mlx_clear_window(game_elts->mlx_ptr, game_elts->win_ptr);
	mapping_assets_to_the_grid(game_elts);
	game_elts->move_count++;
	ft_printf("number of movements: %d\n", game_elts->move_count);
}

/*
	move_player - main player movement function with full validation and updates
	@param game_elts : game structure containing all game state
	@param dx : X movement delta (-1, 0, or 1)
	@param dy : Y movement delta (-1, 0, or 1)
	@return : EXIT_SUCCESS if move completed, error code if invalid move

	Workflow:
	1. Calculate target position from current position + deltas
	2. Validate move legality (boundaries, walls)
	3. Process game logic for target cell content
	4. Update player position and refresh display
	5. Handle special case for victory exit

	Security: All moves validated before execution
	Usage: Called by key press handler for directional movement
*/
int	move_player(t_game *game_elts, int dx, int dy)
{
	int		old_x;
	int		old_y;
	int		new_x;
	int		new_y;
	char	target_cell;

	old_x = game_elts->player_x;
	old_y = game_elts->player_y;
	new_x = game_elts->player_x + dx;
	new_y = game_elts->player_y + dy;
	if (validate_move(game_elts, new_x, new_y) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	target_cell = game_elts->grid[new_y][new_x];
	handle_game_logic(game_elts, target_cell);
	if (target_cell == 'E' && game_elts->collectible_left == 0)
		return (EXIT_SUCCESS);
	game_elts->player_x = new_x;
	game_elts->player_y = new_y;
	update_grid_and_render(game_elts, old_x, old_y, target_cell);
	return (EXIT_SUCCESS);
}

/*
	handle_key_press - processes keyboard input and triggers appropriate actions
	@param keycode : X11 keycode from key press event
	@param game_elts : game structure for movement and cleanup operations
	@return : EXIT_SUCCESS after processing input

	Key Mappings:
	- Escape: Exit game immediately
	- W/Up Arrow: Move up (dy = -1)
	- A/Left Arrow: Move left (dx = -1)
	- D/Right Arrow: Move right (dx = 1)
	- S/Down Arrow: Move down (dy = 1)

	Usage: Registered as MLX key press callback function
*/
int	handle_key_press(int keycode, t_game *game_elts)
{
	if (keycode == XK_Escape)
		clean_and_close_game(game_elts);
	else if (keycode == XK_w || keycode == XK_Up)
		move_player(game_elts, 0, -1);
	else if (keycode == XK_a || keycode == XK_Left)
		move_player(game_elts, -1, 0);
	else if (keycode == XK_d || keycode == XK_Right)
		move_player(game_elts, 1, 0);
	else if (keycode == XK_s || keycode == XK_Down)
		move_player(game_elts, 0, 1);
	return (EXIT_SUCCESS);
}
