/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:34:13 by pafroidu          #+#    #+#             */
/*   Updated: 2025/05/01 12:34:15 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	- prevent overflow in nmemb * size check
	if size > SIZE_MAX / nmemb, the multiplication would exceed SIZE_MAX
	(can't do size * nmemb >= SIZE_MAX check because we can't do the * at all 
	without being sure it fits first)
	- check is only done when nmemb != 0 to avoid division by zero.

	- (size_t)-1 gives the maximum value representable by size_t
	used to avoid overflow without including <stdint.h>
	and we can't hardcode max_size_t = 18446744073709551615;
	- (size_t)-1) explicit cast, gives the biggest size_t value
*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	size_t			max_size_t;
	size_t			total_size_to_allocate;
	void			*result;
	unsigned char	*converted_result;

	i = 0;
	max_size_t = ((size_t)-1);
	if (nmemb != 0 && size > max_size_t / nmemb)
		return (NULL);
	if (nmemb == 0 || size == 0)
		total_size_to_allocate = 1;
	else
		total_size_to_allocate = nmemb * size;
	result = malloc(total_size_to_allocate);
	if (!result)
		return (NULL);
	converted_result = (unsigned char *)result;
	while (i < total_size_to_allocate)
	{
		converted_result[i] = 0;
		i++;
	}
	return (result);
}
