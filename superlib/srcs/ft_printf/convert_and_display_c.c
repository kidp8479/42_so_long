/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_and_display_c.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:55:33 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/14 18:55:23 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
	- in variadic functions, arguments of type char and short are
	promoted to int. Even when expecting a char, the argument must
	be retrieved using va_arg(ap, int).
	- return ft_... directly because it's based on the write function and
	write returns a size_t
*/

int	convert_and_display_c(va_list ap)
{
	int	c;

	c = va_arg(ap, int);
	return (ft_putchar_fd_int(c, 1));
}
