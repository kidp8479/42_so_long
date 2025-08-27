/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:18:25 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/03 12:18:27 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	- if the list pointer is null, do nothing 
	- if the list is empty, set new as the first element 
	- if not empty, find the last element and link new to it 
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
