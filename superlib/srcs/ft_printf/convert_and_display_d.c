/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_and_display_d.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:56:15 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/14 18:55:29 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
	- %d and %i are treated identically: both print signed
	decimal integers (base 10)
	- In printf, there is no difference between %d and %i for output.
*/

int	convert_and_display_d(va_list ap)
{
	int		d;
	char	*str;
	int		count;

	d = va_arg(ap, int);
	str = ft_itoa(d);
	if (!str)
		return (-1);
	count = ft_putstr_fd_int(str, 1);
	free(str);
	return (count);
}
