/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:33:04 by abetemps          #+#    #+#             */
/*   Updated: 2025/01/14 16:32:20 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_improved.h"

char	**ft_split(char const *s, char c)
{
	char	**nstrs;
	int		i;
	int		j;
	int		x;

	i = 0;
	j = 0;
	x = 0;
	nstrs = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!nstrs)
		return (NULL);
	while (s[i] && ft_count_words(s, c) != 0)
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			nstrs[x++] = ft_substr(s, j, i - j);
		if (nstrs[x - 1] == NULL)
			return (ft_freestr_tab(nstrs));
	}
	nstrs[x] = NULL;
	return (nstrs);
}
