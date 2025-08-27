/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:23:02 by pafroidu          #+#    #+#             */
/*   Updated: 2025/04/25 11:23:04 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	- fills n bytes of memory starting at memory location s, with the value c
	- c is interpreted as an unsigned char
	- cast pointeur void *s to work with octet
	- no need  to check for n == 0 or if !s (like not said in the man)
	it's the programmer responsability to use them well
	it could segfault crash and erase memory if not used properly but it's 
	"normal"
*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	uc;
	size_t			i;

	ptr = (unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		ptr[i] = uc;
		i++;
	}
	return (s);
}
