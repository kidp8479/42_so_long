/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_array_of.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:29:07 by pafroidu          #+#    #+#             */
/*   Updated: 2025/07/26 00:20:31 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* prints an array of strings */

#include "push_swap.h"

void	print_strs_tab(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	ft_printf("content of *argv[]");
	ft_printf("\n**********************************************************\n");
	while (argv[i])
	{
		ft_printf("argv[%d] = %s\n", i, argv[i]);
		i++;
	}
	ft_printf("************************************************************\n");
}

void	print_int_tab(int *tab, int len)
{
	int	i;

	i = 0;
	ft_printf("if valid, content of *argv[] converted into *int");
	ft_printf("\n**********************************************************\n");
	while (i < len)
	{
		ft_printf("int[%d] = %d\n", i, tab[i]);
		i++;
	}
	ft_printf("************************************************************\n");
}
