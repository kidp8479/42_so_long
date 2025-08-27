/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:01:52 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/03 13:01:54 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	- delete all nodes and free the list
	- tmp is used to not lose access when freeing
	- del is user defined and must free the content
	- *lst = NULL in the end because we would have a pointer to a free mem zone
	and it's "dangerous"
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*tmp;

	current = *lst;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		(*del)(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
