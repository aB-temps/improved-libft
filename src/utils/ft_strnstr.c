/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:55:40 by abetemps          #+#    #+#             */
/*   Updated: 2025/01/14 16:32:20 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_improved.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while ((i + j) < len && big[j])
	{
		i = 0;
		while (little[i] == big[j + i] && i + j < len)
		{
			i++;
			if (little[i] == '\0')
				return (&((char *)big)[j]);
		}
		j++;
	}
	return (NULL);
}
