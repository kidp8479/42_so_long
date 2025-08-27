/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:58:32 by pafroidu          #+#    #+#             */
/*   Updated: 2025/07/26 00:18:12 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	- memcpy does not handle buffer overlap
	- before manipulating a void pointer,
	we need to cast it so that we manipulate octets -> unsigned char
	- no need  to check for n == 0 or if !dest || !src (like not said in the man)
	it's the programmer responsability to use them well
	it could segfault crash and erase memory if not used properly
	but it's "normal"
	- !! memcpy does not add auto a '\0' when dealing with a string, beware of
	undefined behavior
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*uc_dest;
	const unsigned char	*uc_src;
	size_t				i;

	uc_dest = (unsigned char *)dest;
	uc_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		uc_dest[i] = uc_src[i];
		i++;
	}
	return (dest);
}
