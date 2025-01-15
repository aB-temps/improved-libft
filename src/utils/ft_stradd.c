/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:57:50 by abetemps          #+#    #+#             */
/*   Updated: 2025/01/14 16:32:20 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_improved.h"

char	*ft_stradd(char *s1, char *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*ns;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ns = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ns)
		return (ft_freestr(s1));
	while (i < s1_len)
	{
		ns[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
		ns[s1_len++] = s2[i++];
	ns[s1_len] = '\0';
	ft_freestr(s1);
	return (ns);
}
