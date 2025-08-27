/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:55:47 by pafroidu          #+#    #+#             */
/*   Updated: 2025/06/19 14:58:46 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <libft.h>

typedef struct s_format
{
	char	type;
	int		start;
	int		end;
	int		length;

}	t_format;

/* main function */
int		ft_printf(const char *format, ...);

/* parsing utils*/
int		is_format_char(char c);
int		parse_token(const char *format, int i, t_format *out);

/* convert utils */
int		is_valid_base(char *base);
int		ft_putnbr_base_unsigned(unsigned long nbr, char *base);

/* convert and display all %... */
int		dispatch_print_format(t_format *extracted, va_list ap);
int		convert_and_display_c(va_list ap);
int		convert_and_display_s(va_list ap);
int		convert_and_display_p(va_list ap);
int		convert_and_display_d(va_list ap);
int		convert_and_display_i(va_list ap);
int		convert_and_display_u(va_list ap);
int		convert_and_display_xlow(va_list ap);
int		convert_and_display_xup(va_list ap);
int		convert_and_display_percent(void);

#endif
