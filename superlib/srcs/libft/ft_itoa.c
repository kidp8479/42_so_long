/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:42:27 by pafroidu          #+#    #+#             */
/*   Updated: 2025/07/26 00:18:43 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	count_n_len
	- if n < 0 we count one for the '-'
	- n transformed to long nb to avoid overflow

	itoa
	- for 0 in itoa, need to return a string
	allocated with malloc => ft_strdup (we can't free something not mallocd)
	- n transformed to long to handle overflow and INT_MIN
*/

#include "libft.h"

static long	count_n_len(long n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	str_len;
	long	nb;

	nb = n;
	str_len = count_n_len(nb);
	if (nb == 0)
		return (ft_strdup("0"));
	str = ft_calloc(str_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[str_len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb != 0)
	{
		str_len--;
		str[str_len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
