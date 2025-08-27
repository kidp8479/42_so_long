# ███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗
# ██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝
# ███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗
# ╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║
# ███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝
# ╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝

# === General Configuration ===
NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -MMD -MP
RM			= rm -f

# === Directories ===
MLX_DIR			= minilibx-linux
SUPERLIB_DIR	= superlib

# === Libraries ===
MLX_A			= $(MLX_DIR)/libmlx.a
SUPERLIB_A		= $(SUPERLIB_DIR)/superlib.a

# === Includes and Flags ===
INC_DIR			= -Iincludes -I$(SUPERLIB_DIR)/include -I$(MLX_DIR)
SYSTEM_FLAGS	= -lXext -lX11 -lm

# === Sources ===
SRCS		=	srcs/cleanup_error/cleanup_map_structure.c \
				srcs/cleanup_error/error_print_message.c \
				srcs/game/game_handle_screen_data.c \
				srcs/game/game_init.c \
				srcs/game/game_print_ASCII_art.c \
				srcs/main.c \
				srcs/maps/map_check_file_extension.c \
				srcs/maps/map_handle_full_parsing.c \
				srcs/maps/map_list_to_grid.c \
				srcs/maps/map_to_list_parser.c \
				srcs/maps/map_to_list_reader.c \
				srcs/maps/map_to_list_utils2.c \
				srcs/maps/map_to_list_utils.c \
				srcs/maps/map_validate_letters.c \
				srcs/maps/map_validate_path.c \
				srcs/maps/map_validate_walls.c \
				srcs/render/render_handle_load.c \
				srcs/render/render_load_utils.c \
				srcs/render/render_mapping_to_the_grid.c \
				srcs/game/game_handle_gameplay.c \
				srcs/game/game_handle_keys.c

OBJS		= $(SRCS:.c=.o)
DEPS		= $(OBJS:.o=.d)

# === Build Rules ===
all: $(NAME)

$(NAME): $(MLX_A) $(SUPERLIB_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_A) $(SYSTEM_FLAGS) $(SUPERLIB_A)

%.o: %.c
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

$(MLX_A):
	$(MAKE) -C $(MLX_DIR)

$(SUPERLIB_A):
	$(MAKE) -C $(SUPERLIB_DIR)

# === Cleaning ===
clean:
	$(RM) $(OBJS) $(DEPS)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(SUPERLIB_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(SUPERLIB_DIR) fclean

re: fclean all

# === Auto dependencies ===
-include $(DEPS)

.PHONY: all clean fclean re
