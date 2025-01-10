/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:46:53 by abetemps          #+#    #+#             */
/*   Updated: 2024/11/21 03:33:00 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	total_size;

	if (!nmemb || !size)
		return (malloc(0));
	if ((INT_MAX / nmemb) < size)
		return (NULL);
	total_size = nmemb * size;
	array = malloc(total_size);
	if (!array)
		return (NULL);
	ft_bzero(array, total_size);
	return (array);
}