/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:22:36 by pafroidu          #+#    #+#             */
/*   Updated: 2025/06/24 17:55:29 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	frees an array of strings and all its elements
	standard cleanup function for dynamically allocated string arrays
	safely handles NULL arrays without crashing

	@argv: array of strings to free (each string + the array itself)

	note: sets no pointers to NULL, caller responsible for that if needed
	note: safe to call with NULL parameter

	utils for debugging:
	ft_printf("freeing array with %d elements\n", i);
*/

#include "push_swap.h"

void	free_array_args(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
