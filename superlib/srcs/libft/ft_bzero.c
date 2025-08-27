/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:45:18 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/01 15:40:43 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	- puts 0 on n bytes of memory starting at s
	- sets each byte to '\0'
	- no need  to check for n == 0 or if !dest || !src 
	(it's not said in the man)
	- it's the programmer responsability to use them well
	it could segfault crash and erase memory 
	if not used properly but it's "normal"
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
