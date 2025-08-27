/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:32:48 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/03 16:05:39 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	count++ before going to the next node
	otherwise we don't count the first/last one

	- if the list is empty (lst == NULL) size = 0
	- while lst is not NULL
		- increment count
		- ove to lst->next
	return count
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
