/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_and_display_p.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:56:21 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/14 18:55:52 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	- according to printf standard, %p should display
	an adress starting with"0x"
	- if the adress is NULL, display "0x0" OR (nil) in modern GNU/libc and exit
	(but count the chars anyway)
	- cast the ptr to display it as a number, and then in base 16
	- uintptr_t is a type of unsigned int big enough to hold a memory address
*/

int	convert_and_display_p(va_list ap)
{
	int			count;
	void		*ptr;
	uintptr_t	address;

	count = 0;
	ptr = va_arg(ap, void *);
	if (!ptr)
	{
		count += ft_putstr_fd_int("(nil)", 1);
		return (count);
	}
	count += ft_putstr_fd_int("0x", 1);
	address = (uintptr_t)ptr;
	count += ft_putnbr_base_unsigned(address, "0123456789abcdef");
	return (count);
}
