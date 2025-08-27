/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:25:45 by pafroidu          #+#    #+#             */
/*   Updated: 2025/06/24 18:28:15 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	classic bubble sort algorithm for integer arrays
	sorts array in ascending order using adjacent element comparisons
	used by assign_index() to establish value ordering for index assignment

	@tab: integer array to sort in place
	@len: length of the array

	note: O(n²) complexity but acceptable for push_swap input sizes
	note: modifies original array - caller should work on copy if needed
	note: optimized with early termination (len - 1 - i boundary)
	
	algorithm: repeatedly bubbles largest unsorted element to its position
	
	utils for debugging:
	print_int_tab(tab, len);
*/

#include "push_swap.h"

void	bubble_sort_int(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			if (tab[j] > tab[j + 1])
				ft_swap_int(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}
