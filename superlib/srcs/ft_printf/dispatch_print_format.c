/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_print_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:54:25 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/14 18:56:30 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dispatch_print_format(t_format *extracted, va_list ap)
{
	int	count;

	count = 0;
	if (extracted->type == 'c')
		count += convert_and_display_c(ap);
	else if (extracted->type == 's')
		count += convert_and_display_s(ap);
	else if (extracted->type == 'p')
		count += convert_and_display_p(ap);
	else if (extracted->type == 'd')
		count += convert_and_display_d(ap);
	else if (extracted->type == 'i')
		count += convert_and_display_i(ap);
	else if (extracted->type == 'u')
		count += convert_and_display_u(ap);
	else if (extracted->type == 'x')
		count += convert_and_display_xlow(ap);
	else if (extracted->type == 'X')
		count += convert_and_display_xup(ap);
	else if (extracted->type == '%')
		count += convert_and_display_percent();
	return (count);
}
