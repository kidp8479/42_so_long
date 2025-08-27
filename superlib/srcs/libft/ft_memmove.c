/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:33:19 by pafroidu          #+#    #+#             */
/*   Updated: 2025/07/26 00:18:23 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	- similar to memcpy but memmove handles buffer overlap
	- memmove can handle any type of data != strcpy only str, memmove does not
	add a null terminator when used on strs, needs to be added by hand
	- before manipulating a void pointer, we need to cast it
	so that we manipulate octets -> unsigned char

	memmove cases :

	1) <-----s----->                start at end of s
	                 <-----d----->

	2) <-----s----->                start at end of s
	            <-----d----->

	3) <-----s----->                no action
	   <-----d----->

	4)          <-----s----->       start at beginning of s
   	<-----d----->

	5)               <-----s----->  start at beginning of s
	   <-----d----->

	- (uc_dest <= uc_src) memory adress position comparison,
	dest located before src in memory - copy left to right
	- (uc_dest >= uc_src) - copry right to left
	- i-- to fall back on the first valid element n - 1 of the tab
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest <= src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		}
	}
	return (dest);
}
