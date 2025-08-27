/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:38:22 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/02 09:38:24 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	trim all chars from set at start + end of s

	- start = first char not in set
	- end = last char not in set

	- if start > end -> return empty string

	- ft_substr(s, start, end - start + 1)

	- if set empty -> return full s copy
	- if s empty -> return empty string
	- if all chars in s are in set -> return empty string

	- check is_char_in_set manually (loop)
	- end > start → makes sure we don’t trim past start
*/

#include "libft.h"

static int	is_in_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		start;
	int		end;

	end = ft_strlen(s1);
	start = 0;
	while (is_in_set(s1[start], set) && s1[start] != '\0')
		start++;
	while (is_in_set(s1[end - 1], set) && end > start)
		end--;
	result = ft_substr(s1, start, (end - start));
	if (!result)
		return (NULL);
	return (result);
}
