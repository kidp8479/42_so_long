/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:48:00 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/14 18:57:03 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* modified versions for printf, return int */

#include "ft_printf.h"

int	ft_putstr_fd_int(char *s, int fd)
{
	int	i;
	int	len;

	i = 0;
	if (!s)
		return (write(fd, "(null)", 6));
	len = ft_strlen(s);
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (len);
}
