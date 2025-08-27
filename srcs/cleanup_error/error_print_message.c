/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print_message.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:59:56 by pafroidu          #+#    #+#             */
/*   Updated: 2025/08/02 10:25:08 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	print_error_msg - prints formatted error messages
	@param pre : prefix message (ex: "map:")
	@param main : main error description
	@param post : additional information

	Format: Always starts with "Error\n", then custom messages
	Usage: Centralizes all error message formatting across parsing
*/
void	print_error_msg(char *pre, char *main, char *post)
{
	ft_printf("Error\n");
	if (pre)
		ft_printf("%s ", pre);
	if (main)
		ft_printf("%s\n", main);
	if (post)
		ft_printf("%s\n", post);
}
