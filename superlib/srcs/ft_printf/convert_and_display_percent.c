/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_and_display_percent.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:55:11 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/14 18:55:56 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_and_display_percent(void)
{
	int	count;

	count = 0;
	count += ft_putchar_fd_int('%', 1);
	return (count);
}
