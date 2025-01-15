/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:03:26 by abetemps          #+#    #+#             */
/*   Updated: 2025/01/14 16:32:20 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_improved.h"

void	ft_putchar_fd(char c, ssize_t *len, int fd)
{
	int	err;

	err = 0;
	if (!fd)
	{
		write(STDERR_FILENO, "Invalid file descriptor\n", 24);
		*len = -1;
		return ;
	}
	err = write(fd, &c, 1);
	if (err == -1)
		*len = err;
	else
		*len += 1;
}

void	ft_putstr_fd(char *s, ssize_t *len, int fd)
{
	size_t	length;
	int		err;

	err = 0;
	if (!fd)
	{
		write(STDERR_FILENO, "Invalid file descriptor\n", 24);
		*len = -1;
		return ;
	}
	if (!s)
		return (ft_putstr_fd("(null)", len, fd));
	length = ft_strlen(s);
	err = write(fd, s, length);
	if (err == -1)
		*len = err;
	else
		*len += length;
}

void	ft_putnbr_fd(long long n, ssize_t *len, int fd)
{
	if (*len == -1)
		return ;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", len, fd));
	else if (*len != -1)
	{
		if (n < 0)
		{
			n *= -1;
			ft_putchar_fd('-', len, fd);
			if (*len == -1)
				return ;
		}
		if (n > 9)
			ft_putnbr_fd(n / 10, len, fd);
		ft_putchar_fd(n % 10 + '0', len, fd);
		if (*len == -1)
			return ;
	}
}

void	ft_putnbr_base_fd(unsigned long int nbr, char c, ssize_t *len, int fd)
{
	unsigned long int	base_len;
	char				*base;

	if (*len == -1)
		return ;
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	base_len = ft_strlen(base);
	if (nbr >= base_len && *len != -1)
		ft_putnbr_base_fd(nbr / base_len, c, len, fd);
	ft_putchar_fd(base[nbr % base_len], len, fd);
}
