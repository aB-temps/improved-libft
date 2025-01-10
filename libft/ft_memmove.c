/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:20:46 by abetemps          #+#    #+#             */
/*   Updated: 2024/11/20 23:55:55 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_src;
	unsigned char	*ptr_dest;

	ptr_src = (unsigned char *)src;
	ptr_dest = (unsigned char *)dest;
	if (ptr_dest <= ptr_src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			ptr_dest[n - 1] = ptr_src[n - 1];
			n--;
		}
	}
	return (dest);
}