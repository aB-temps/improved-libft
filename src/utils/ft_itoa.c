/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 22:39:13 by abetemps          #+#    #+#             */
/*   Updated: 2025/01/14 16:32:20 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_improved.h"

static char	ft_slice(unsigned int nb, int index)
{
	while (index-- > 0)
		nb /= 10;
	return (((nb % 10) + '0'));
}

char	*ft_itoa(int n)
{
	int				i;
	int				len;
	unsigned int	nb;
	char			*s;

	i = 0;
	if (n < 0)
		nb = (unsigned int)-n;
	else
		nb = (unsigned int)n;
	len = ft_uintlen(nb);
	s = malloc(sizeof(char) * (len + 1 + (n <= 0)));
	if (!s)
		return (NULL);
	s[len + (n <= 0)] = '\0';
	if (n < 0)
		s[0] = '-';
	if (n == 0)
		s[0] = '0';
	while (i < len)
	{
		s[len - 1 - i + (n < 0)] = ft_slice(nb, i);
		i++;
	}
	return (s);
}
