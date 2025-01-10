/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:07:54 by abetemps          #+#    #+#             */
/*   Updated: 2025/01/10 18:58:51 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/improved_libft.h"

char	*ft_strndup(char *s, size_t n)
{
	char	*ns;
	size_t	i;

	i = 0;
	ns = malloc(sizeof(char) * (n + 1));
	if (!ns)
		return (NULL);
	while (s[i] && i < n)
	{
		ns[i] = s[i];
		i++;
	}
	ns[i] = '\0';
	return (ns);
}