/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:56:39 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/14 19:17:34 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	process_format_loop
 	Note on weird 'i' increments (because of the norm):
	- valid '%s', i increased by the token.length
	- for solo % or invalid '%q', i incremented once if we need to print only %,
	and another time with ++i if we need to print the next i
	- for other chars, normal i++
 */

static int	validate_format(const char *format)
{
	if (!format)
		return (-1);
	if (format[0] == '\0')
		return (0);
	return (1);
}

static int	process_format_loop(const char *format, va_list ap)
{
	int			count;
	int			i;
	t_format	extracted;

	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] && is_format_char(format[i + 1]))
		{
			parse_token(format, i, &extracted);
			count += dispatch_print_format(&extracted, ap);
			i += extracted.length;
		}
		else if (format[i] == '%')
		{
			count += ft_putchar_fd_int('%', 1);
			if (format [i + 1] != '\0')
				count += ft_putchar_fd_int(format[++i], 1);
			i++;
		}
		else
			count += ft_putchar_fd_int(format[i++], 1);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int			count;
	va_list		ap;
	int			check;

	count = 0;
	check = validate_format(format);
	if (check <= 0)
		return (check);
	va_start(ap, format);
	count = process_format_loop(format, ap);
	va_end(ap);
	return (count);
}
