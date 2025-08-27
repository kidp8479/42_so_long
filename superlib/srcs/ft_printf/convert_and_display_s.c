/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_and_display_s.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:56:29 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/14 18:56:00 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	POSIX behavior :
	- If a NULL pointer is passed, it prints (null) (not undefined behavior).

	man 3 printf :
	- %s prints a string as defined by the common C convention:
	this means it expects a pointer to a null-terminated
	sequence of characters (char *). The format does not handle NULL explicitly
	by the C standard. Passing a null pointer results in undefined behavior,
	but most implementations (like glibc) display "(null)" to avoid crashing.
*/

int	convert_and_display_s(va_list ap)
{
	char	*s;
	int		count;

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	count = ft_putstr_fd_int(s, 1);
	return (count);
}
