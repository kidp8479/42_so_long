/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_array_to_tab_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:43:09 by pafroidu          #+#    #+#             */
/*   Updated: 2025/06/26 11:42:22 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	converts validated string array to integer array
	final step of parsing pipeline that transforms strings to usable integers
	allocates memory for integer array and performs conversion
	
	@final_tab: validated array of numeric strings
	@out_int_tab_len: pointer to store the length of created integer array
	
	returns: dynamically allocated array of integers
	note: assumes all strings are pre-validated (no error checking on conversion)
	note: caller responsible for freeing returned array
	note: sets output length for later use in stack construction

	utils for debugging:
	print_int_tab(int_tab, final_tab_len);

	** adapted version for superlibft, more generic than the one in push_swap **
*/

#include "push_swap.h"

int	*str_array_to_int(char **final_tab, int *out_int_tab_len)
{
	int	*int_tab;
	int	final_tab_len;
	int	i;

	final_tab_len = get_array_len(final_tab);
	int_tab = malloc(sizeof(int) * (final_tab_len));
	if (!int_tab)
	{
		*out_int_tab_len = -1;
		return (NULL);
	}
	i = 0;
	while (final_tab[i])
	{
		int_tab[i] = ft_atol(final_tab[i]);
		i++;
	}
	*out_int_tab_len = final_tab_len;
	return (int_tab);
}
