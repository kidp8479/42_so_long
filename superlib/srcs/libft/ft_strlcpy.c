/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:36:34 by pafroidu          #+#    #+#             */
/*   Updated: 2025/04/26 18:36:35 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	- copy src into dst within dst size, null-terminating the result 
	- if dst size > 0 returns the length of src
	- no copy occurs if dst size == 0, but the length is still returned
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (siz == 0)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < (siz - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
