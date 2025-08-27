/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:42:51 by pafroidu          #+#    #+#             */
/*   Updated: 2025/06/26 11:42:36 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	simple array length counter for string arrays
	can't reuse count_total_tokens() here since we need length of 
	already consolidated array, not tokens within arguments
	
	@array: null-terminated string array to count
	
	returns: number of elements in the array (excluding NULL terminator)
	note: exits with error if array is NULL (shouldn't happen in normal flow)

	utils for debugging:
	ft_printf("array length: %d\n", i);

	** adapted version for superlibft, more generic than the one in push_swap **
*/

#include "push_swap.h"

int	get_array_len(char **array)
{
	int	i;

	if (!array)
		return (0);
	i = 0;
	while (array[i])
		i++;
	return (i);
}
