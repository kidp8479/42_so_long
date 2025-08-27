/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:07:10 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/14 18:57:00 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* modified versions for printf, return int */

#include "ft_printf.h"

int	ft_putnbr_fd_int(int nb, int fd)
{
	char	c;
	int		count;

	count = 0;
	if (nb == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (nb < 0)
	{
		count += write(fd, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		count += ft_putnbr_fd_int(nb / 10, fd);
	}
	c = (nb % 10) + '0';
	count += write(fd, &c, 1);
	return (count);
}
