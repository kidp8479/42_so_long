/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:47:56 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/02 13:47:59 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*map_str;
	unsigned int	str_len;

	str_len = ft_strlen(s);
	map_str = ft_calloc((str_len + 1), sizeof(char));
	if (!map_str)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		map_str[i] = (*f)(i, s[i]);
		i++;
	}
	map_str[i] = '\0';
	return (map_str);
}
