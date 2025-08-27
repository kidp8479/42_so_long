/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_and_display_xlow.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:55:29 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/14 18:56:14 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_and_display_xlow(va_list ap)
{
	unsigned int	us_low;
	int				count;

	count = 0;
	us_low = va_arg(ap, unsigned int);
	count += ft_putnbr_base_unsigned(us_low, "0123456789abcdef");
	return (count);
}
