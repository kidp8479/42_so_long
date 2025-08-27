/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:26:06 by pafroidu          #+#    #+#             */
/*   Updated: 2025/06/24 18:31:10 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	utility function to swap two integers by reference
	classic three-way swap using temporary variable
	used by bubble_sort_int() for element exchanges

	@a: pointer to first integer
	@b: pointer to second integer

	note: modifies original values through pointer dereferencing
	note: safe and standard swapping technique

	example: if a=5, b=3 then after swap: a=3, b=5

	utils for debugging:
	ft_printf("swapping %d and %d\n", *a, *b);
*/

#include "push_swap.h"

void	ft_swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
