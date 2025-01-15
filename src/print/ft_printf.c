/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:48:14 by abetemps          #+#    #+#             */
/*   Updated: 2025/01/14 16:32:20 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_improved.h"

void	ft_putaddr_fd(void *ptr, ssize_t *len, int fd)
{
	if (*len == -1)
		return ;
	if (!ptr)
		return (ft_putstr_fd("(nil)", len, fd));
	ft_putstr_fd("0x", len, fd);
	if (*len == -1)
		return ;
	ft_putnbr_base_fd((unsigned long int)ptr, 'x', len, fd);
}

void	ft_handle_datatype(char c, va_list *cursor, ssize_t *length, int fd)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(*cursor, int), length, fd);
	else if (c == 's')
		ft_putstr_fd(va_arg(*cursor, char *), length, fd);
	else if (c == 'p')
		ft_putaddr_fd(va_arg(*cursor, void *), length, fd);
	else if (c == 'i' || c == 'd')
		ft_putnbr_fd(va_arg(*cursor, int), length, fd);
	else if (c == 'u')
		ft_putnbr_fd(va_arg(*cursor, unsigned int), length, fd);
	else if (c == 'x' || c == 'X')
		ft_putnbr_base_fd(va_arg(*cursor, unsigned int), c, length, fd);
	else if (c == '%')
		ft_putchar_fd('%', length, fd);
	else
		*length = -1;
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	cursor;
	size_t	i;
	ssize_t	length;

	i = 0;
	length = 0;
	va_start(cursor, str);
	if (!str)
		return (-1);
	while (str[i] && length != -1)
	{
		if (str[i] == '%')
			ft_handle_datatype(str[++i], &cursor, &length, fd);
		else
			ft_putchar_fd(str[i], &length, fd);
		i++;
	}
	va_end(cursor);
	return (length);
}
