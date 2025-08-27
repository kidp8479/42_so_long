/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:42:47 by pafroidu          #+#    #+#             */
/*   Updated: 2025/06/24 17:11:06 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	converts string to long integer with overflow protection
	enhanced version of atoi() that returns long to detect int range violations
	handles whitespace and explicit signs like standard atol()
	
	@nptr: string representation of integer to convert

	returns: long value of the string
	note: used to validate if input fits in INT_MIN to INT_MAX range
	note: handles leading whitespace (spaces, tabs, newlines)
	note: stops conversion at first non-digit character

	utils for debugging:
	ft_printf("converted '%s' to %ld\n", nptr, result);
*/

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
