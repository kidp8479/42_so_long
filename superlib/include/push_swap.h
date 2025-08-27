/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:13:47 by pafroidu          #+#    #+#             */
/*   Updated: 2025/07/01 14:13:54 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "ft_printf.h"
# include "libft.h"

/* === struct for a node === */
/* typedef struct s_node
{
	int				content;
	int				index;
	struct s_node	*next;

}	t_node; */

/* ******************** parsing functions ********************* */
/* === parsing utils === */
void	free_array_args(char **argv);
long	ft_atol(const char *nptr);
int		get_array_len(char **array);
int		*str_array_to_int(char **final_tab, int *out_int_tab_len);

/* === algorithm utils === */
void	ft_swap_int(int *a, int *b);
void	**list_to_tab_ptr(t_list *lst);
void	bubble_sort_int(int *tab, int len);

/* === adebug utils === */
void	print_list(t_list *list);
void	print_strs_tab(char **argv);
void	print_int_tab(int *tab, int len);

#endif
