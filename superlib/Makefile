# === General Configuration ===

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -MMD -MP
AR			= ar rcs
RM			= rm -f
INCDIR		= -Iinclude

# === Target names ===

NAME_LIBFT		= libft.a
NAME_PRINTF		= ft_printf.a
NAME_GNL		= get_next_line.a
NAME_GNL_BONUS	= get_next_line_bonus.a
NAME_SUPERLIB	= superlib.a

# === Source files ===

SRC_LIBFT = \
	srcs/libft/ft_atoi.c \
	srcs/libft/ft_bzero.c \
	srcs/libft/ft_calloc.c \
	srcs/libft/ft_isalnum.c \
	srcs/libft/ft_isalpha.c \
	srcs/libft/ft_isascii.c \
	srcs/libft/ft_isdigit.c \
	srcs/libft/ft_isprint.c \
	srcs/libft/ft_itoa.c \
	srcs/libft/ft_memchr.c \
	srcs/libft/ft_memcmp.c \
	srcs/libft/ft_memcpy.c \
	srcs/libft/ft_memmove.c \
	srcs/libft/ft_memset.c \
	srcs/libft/ft_putchar_fd.c \
	srcs/libft/ft_putendl_fd.c \
	srcs/libft/ft_putnbr_fd.c \
	srcs/libft/ft_putstr_fd.c \
	srcs/libft/ft_putchar_fd_int.c \
	srcs/libft/ft_putnbr_fd_int.c \
	srcs/libft/ft_putstr_fd_int.c \
	srcs/libft/ft_split.c \
	srcs/libft/ft_strchr.c \
	srcs/libft/ft_strdup.c \
	srcs/libft/ft_striteri.c \
	srcs/libft/ft_strjoin.c \
	srcs/libft/ft_strlcat.c \
	srcs/libft/ft_strlcpy.c \
	srcs/libft/ft_strlen.c \
	srcs/libft/ft_strmapi.c \
	srcs/libft/ft_strncmp.c \
	srcs/libft/ft_strnstr.c \
	srcs/libft/ft_strrchr.c \
	srcs/libft/ft_strtrim.c \
	srcs/libft/ft_substr.c \
	srcs/libft/ft_tolower.c \
	srcs/libft/ft_toupper.c \
	srcs/libft/ft_lstnew_bonus.c \
	srcs/libft/ft_lstadd_front_bonus.c \
	srcs/libft/ft_lstsize_bonus.c \
	srcs/libft/ft_lstlast_bonus.c \
	srcs/libft/ft_lstadd_back_bonus.c \
	srcs/libft/ft_lstdelone_bonus.c \
	srcs/libft/ft_lstclear_bonus.c \
	srcs/libft/ft_lstiter_bonus.c \
	srcs/libft/ft_lstmap_bonus.c

SRC_PRINTF = \
	srcs/ft_printf/convert_and_display_c.c \
	srcs/ft_printf/convert_and_display_d.c \
	srcs/ft_printf/convert_and_display_i.c \
	srcs/ft_printf/convert_and_display_p.c \
	srcs/ft_printf/convert_and_display_percent.c \
	srcs/ft_printf/convert_and_display_s.c \
	srcs/ft_printf/convert_and_display_u.c \
	srcs/ft_printf/convert_and_display_xlow.c \
	srcs/ft_printf/convert_and_display_xup.c \
	srcs/ft_printf/convert_utils.c \
	srcs/ft_printf/dispatch_print_format.c \
	srcs/ft_printf/ft_printf.c \
	srcs/ft_printf/parsing_utils.c

SRC_GNL = \
	srcs/get_next_line/get_next_line.c \
	srcs/get_next_line/get_next_line_utils.c

SRC_GNL_BONUS = \
	srcs/get_next_line/get_next_line_bonus.c \
	srcs/get_next_line/get_next_line_utils_bonus.c

SRC_MISC = \
	srcs/push_swap/bubble_sort_int.c \
	srcs/push_swap/free_array_args.c \
	srcs/push_swap/ft_atol.c \
	srcs/push_swap/ft_swap_int.c \
	srcs/push_swap/get_array_len.c \
	srcs/push_swap/list_to_tab.c \
	srcs/push_swap/str_array_to_tab_int.c \
	srcs/push_swap/print_list.c \
	srcs/push_swap/print_array_of.c \

# === Object files ===

OBJ_LIBFT		= $(SRC_LIBFT:.c=.o)
OBJ_PRINTF		= $(SRC_PRINTF:.c=.o)
OBJ_GNL			= $(SRC_GNL:.c=.o)
OBJ_GNL_BONUS	= $(SRC_GNL_BONUS:.c=.o)
OBJ_MISC		= $(SRC_MISC:.c=.o)

DEP_LIBFT		= $(OBJ_LIBFT:.o=.d)
DEP_PRINTF		= $(OBJ_PRINTF:.o=.d)
DEP_GNL			= $(OBJ_GNL:.o=.d)
DEP_GNL_BONUS	= $(OBJ_GNL_BONUS:.o=.d)
DEP_MISC		= $(OBJ_MISC:.o=.d)

# === Compilation rule ===

%.o: %.c
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

# === Main targets ===

all: libft printf gnl superlib

libft: $(NAME_LIBFT)

$(NAME_LIBFT): $(OBJ_LIBFT)
	$(AR) $@ $^

printf: $(NAME_PRINTF)

$(NAME_PRINTF): $(OBJ_PRINTF)
	$(AR) $@ $^

gnl: $(NAME_GNL)

$(NAME_GNL): $(OBJ_GNL)
	$(AR) $@ $^

gnl_bonus: $(NAME_GNL_BONUS)

$(NAME_GNL_BONUS): $(OBJ_GNL_BONUS)
	$(AR) $@ $^

# === Superlib target (libft + printf + gnl + gnl_bonus) ===

superlib: $(NAME_SUPERLIB)

$(NAME_SUPERLIB): $(OBJ_LIBFT) $(OBJ_PRINTF) $(OBJ_GNL) $(OBJ_GNL_BONUS) $(OBJ_MISC)
	$(AR) $@ $^

# === Cleaning ===

clean:
	$(RM) $(OBJ_LIBFT) $(OBJ_PRINTF) $(OBJ_GNL) $(OBJ_GNL_BONUS) $(OBJ_MISC)
	$(RM) $(DEP_LIBFT) $(DEP_PRINTF) $(DEP_GNL) $(DEP_GNL_BONUS) $(DEP_MISC)

fclean: clean
	$(RM) $(NAME_LIBFT) $(NAME_PRINTF) $(NAME_GNL) $(NAME_GNL_BONUS) $(NAME_SUPERLIB)

re: fclean all

# === Include dependencies ===

-include $(DEP_LIBFT) $(DEP_PRINTF) $(DEP_GNL) $(DEP_GNL_BONUS) $(DEP_MISC)

.PHONY: all libft printf gnl gnl_bonus superlib clean fclean re