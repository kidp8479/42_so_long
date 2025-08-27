/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:25:10 by pafroidu          #+#    #+#             */
/*   Updated: 2025/07/26 00:19:35 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	converts linked list stack to integer array
	creates array copy of stack content for easier manipulation
	used by assign_index() to enable sorting operations on stack data

	@stack_a: linked list stack to convert

	returns: dynamically allocated array containing stack content values
	note: caller responsible for freeing returned array
	note: preserves original stack order in the array
	note: exits program on malloc failure (should use free_and_exit instead)

	example: stack 4→2→1→3→NULL becomes array [4, 2, 1, 3]

	utils for debugging:
	print_int_tab(tab, stack_a_len);

	** adapted version for superlibft, more generic than the one in push_swap **
*/

#include "push_swap.h"

void	**list_to_tab_ptr(t_list *lst)
{
	int		lst_len;
	void	**tab;
	int		i;
	t_list	*current;

	if (!lst)
		return (NULL);
	lst_len = ft_lstsize(lst);
	tab = malloc(sizeof(void *) * (lst_len + 1));
	if (!tab)
		return (NULL);
	i = 0;
	current = lst;
	while (i < lst_len && current)
	{
		tab[i] = current->content;
		current = current->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
