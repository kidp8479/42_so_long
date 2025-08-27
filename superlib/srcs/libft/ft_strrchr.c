/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:02:04 by pafroidu          #+#    #+#             */
/*   Updated: 2025/04/27 17:02:08 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	- last found initialize to NULL
	- we save the char to find inside the pointer last_found evertime we find it 
	while iterating on s.
	- if the char is never found last_found stays NULL
	- (unsigned char)s[i] to compare uc with uc
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc;
	char			*last_found;
	size_t			i;

	uc = (unsigned char)c;
	last_found = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == uc)
			last_found = (char *)&s[i];
		i++;
	}
	if (uc == '\0')
		return ((char *)&s[i]);
	return (last_found);
}
