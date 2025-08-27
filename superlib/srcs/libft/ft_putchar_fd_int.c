/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:46:03 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/14 18:56:52 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* modified versions for printf, return int */

#include "ft_printf.h"

int	ft_putchar_fd_int(char c, int fd)
{
	return (write(fd, &c, 1));
}
