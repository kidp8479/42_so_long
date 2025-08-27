/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_and_display_i.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:56:18 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/14 18:55:46 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	- %d and %i are treated identically: both print signed
	decimal integers (base 10)
	- In printf, there is no difference between %d and %i for output.
*/

int	convert_and_display_i(va_list ap)
{
	int		i;
	char	*str;
	int		count;

	count = 0;
	i = va_arg(ap, int);
	str = ft_itoa(i);
	if (!str)
		return (-1);
	count = ft_putstr_fd_int(str, 1);
	free(str);
	return (count);
}
