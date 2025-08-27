/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:13:39 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/01 15:00:01 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	/*

	- if start begins after s length || len == 0
	we return an empty string '\0' - NULL returned only if a malloc fails

	- we want to extract len char from s starting at start
	if start + len >= s_len : subtring up to s_len - start
	(to prevent UB)
	
	*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > (s_len - start))
		len = s_len - start;
	substr = ft_calloc((len + 1), sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[len] = '\0';
	return (substr);
}
