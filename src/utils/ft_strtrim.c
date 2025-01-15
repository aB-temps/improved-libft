/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:39:23 by abetemps          #+#    #+#             */
/*   Updated: 2025/01/14 16:32:20 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_improved.h"

static int	ft_is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_def_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (ft_is_set(s1[i], set) == 1 && s1[i])
		i++;
	return (i);
}

static int	ft_def_end(char const *s1, char const *set, int start)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (ft_is_set(s1[i], set) == 1 && i >= start)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	size_t	i;
	size_t	len;
	char	*ns;

	start = ft_def_start(s1, set);
	end = ft_def_end(s1, set, start) + 1;
	i = 0;
	len = end - start;
	ns = malloc(sizeof(char) * len + 1);
	if (!ns)
		return (NULL);
	while (i <= len && start < end)
		ns[i++] = s1[start++];
	ns[len] = '\0';
	return (ns);
}
