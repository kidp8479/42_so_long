/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:36:03 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/01 14:36:05 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	alloc + return new string = s1 + s2

	- if s1 or s2 == NULL -> return NULL
	- malloc size = len(s1) + len(s2) + 1
	- copy s1 then s2 into new_string
	- null-terminate manually
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_string = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!new_string)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		new_string[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		new_string[j++] = s2[i++];
	new_string[j] = '\0';
	return (new_string);
}
