/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_and_display_u.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:08:46 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/14 18:56:08 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	- cannot use ft_putnbr_fd because it handles signed ints
	and can cause overflow with unsigned values
*/

int	convert_and_display_u(va_list ap)
{
	unsigned int	us;
	int				count;

	us = va_arg(ap, unsigned int);
	count = ft_putnbr_base_unsigned(us, "0123456789");
	return (count);
}
