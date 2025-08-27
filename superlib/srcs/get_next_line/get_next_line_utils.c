/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:38:31 by pafroidu          #+#    #+#             */
/*   Updated: 2025/07/23 12:10:16 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	utils used in get_next_line:
	- ft_strlen: from libft
	- ft_strdup: from libft
	- ft_strchr_bool_gnl: like strchr, but returns a boolean (true/false)
	- ft_strcpy_gnl: takes a len + void return, update the char* directly
	- ft_strjoin_gnl: strjoin version that handles NULL and frees s1
*/

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup_gnl(const char *str)
{
	size_t	i;
	char	*dest;
	size_t	str_len;

	i = 0;
	str_len = ft_strlen_gnl(str);
	dest = malloc(sizeof(char) * (str_len + 1));
	if (!dest)
		return (NULL);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

bool	ft_strchr_gnl(char	*str, char c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (true);
		i++;
	}
	return (false);
}

void	ft_strcpy_gnl(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*joined_str;

	if (!s1)
	{
		s1 = ft_strdup_gnl("");
		if (!s1)
			return (NULL);
	}
	if (!s2)
	{
		free(s1);
		return (NULL);
	}
	s1_len = ft_strlen_gnl(s1);
	s2_len = ft_strlen_gnl(s2);
	joined_str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!joined_str)
		return (NULL);
	ft_strcpy_gnl(joined_str, s1, s1_len);
	ft_strcpy_gnl(joined_str + s1_len, s2, s2_len);
	free(s1);
	return (joined_str);
}
