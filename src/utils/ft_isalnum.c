/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:32:22 by abetemps          #+#    #+#             */
/*   Updated: 2025/01/10 18:33:52 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/improved_libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) + ft_isdigit(c));
}
