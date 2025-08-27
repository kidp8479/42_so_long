/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:43:35 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/02 17:43:37 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	- allocate memory for a new node, NULL if allocation fails
	- set node->content to the provided content
	- set node->next to NULL
	- return the new node
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
