/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:56:32 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/14 18:56:24 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	- unsigned long for putnbr base because it will be used for %x %X and %p
	conversion and they're of type unsigned int. Long to avoid nbr overflow.
	- don't forget to update count variable twice while using recursivity in
	putnbr unsigned base : 1rst call = befor last digit, 2nd call = last digit

*/

int	is_valid_base(char *base)
{
	int	i;
	int	j;
	int	base_len;

	if (!base)
		return (0);
	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base_unsigned(unsigned long nbr, char *base)
{
	int	base_len;
	int	count;

	if (!is_valid_base(base))
		return (0);
	base_len = ft_strlen(base);
	count = 0;
	if (nbr >= (unsigned long)base_len)
		count += ft_putnbr_base_unsigned(nbr / base_len, base);
	count += ft_putchar_fd_int(base[nbr % base_len], 1);
	return (count);
}
