/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_and_display_xup.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:56:52 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/14 18:56:18 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_and_display_xup(va_list ap)
{
	unsigned int	us_up;
	int				count;

	count = 0;
	us_up = va_arg(ap, unsigned int);
	count += ft_putnbr_base_unsigned(us_up, "0123456789ABCDEF");
	return (count);
}
