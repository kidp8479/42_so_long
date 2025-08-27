/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 20:42:08 by pafroidu          #+#    #+#             */
/*   Updated: 2025/04/26 20:42:10 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	- append src to dst within dst size, null-terminating the result
	returns the total length of the string it tried to create (dst + src)
	- no copy occurs if dst size <= strlen(dst), 
	but the full length is still returned
	Plan :
		- (dst_len < siz && dst[dst_len] != '\0') measure the length of dst, 
		but don't read past siz
		- (dst_len == siz) if no space left in buffer, 
		return size + length of src
		- (src[i] && (dst_len + i) < siz - 1) append src to dst, 
		but don't overflow the buffer
		- (dst_len + i < siz) null-terminate the result if there's room
		- (dst_len + src_len) return the total length the string would have had
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = 0;
	i = 0;
	while (dst_len < siz && dst[dst_len] != '\0')
		dst_len++;
	if (dst_len == siz)
		return (siz + src_len);
	while (src[i] && (dst_len + i) < siz - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i < siz)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
