/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:40:25 by abetemps          #+#    #+#             */
/*   Updated: 2025/01/10 18:34:26 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/improved_libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_element;

	if (!*lst || !lst)
		return ;
	while (*lst)
	{
		lst_element = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = lst_element;
	}
	*lst = NULL;
}