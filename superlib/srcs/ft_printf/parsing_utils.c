/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:56:44 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/14 18:57:11 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_format_char(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	parse_token(const char *format, int i, t_format *out)
{
	if (format[i] == '\0' || format[i + 1] == '\0')
		return (0);
	if (format[i] == '%' && is_format_char(format[i + 1]) == 1)
	{
		out->type = format[i + 1];
		out->start = i;
		out->end = i + 1;
		out->length = (out->end - out->start) + 1;
		return (1);
	}
	return (0);
}
