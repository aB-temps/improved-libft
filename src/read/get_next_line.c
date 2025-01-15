/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:24:21 by abetemps          #+#    #+#             */
/*   Updated: 2025/01/10 16:29:25 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_improved.h"

void	*ft_clear_struct(t_buff *data)
{
	data->full_buff = ft_freestr(data->full_buff);
	data->residual = ft_freestr(data->residual);
	data->valid_line = ft_freestr(data->valid_line);
	return (data);
}

void	ft_init_struct(t_buff *data, char *residual)
{
	data->full_buff = residual;
	data->residual = NULL;
	data->valid_line = NULL;
	data->read_value = 0;
}

void	*ft_extract_line(t_buff *data)
{
	char	*post_nl;

	post_nl = ft_strchr(data->full_buff, '\n');
	if (post_nl++)
	{
		data->valid_line = ft_strndup(data->full_buff, (post_nl
					- data->full_buff));
		if (!data->valid_line)
			return (ft_clear_struct(data));
		data->residual = ft_strndup(post_nl, ft_strlen(data->full_buff));
		if (!data->residual)
			return (ft_clear_struct(data));
	}
	else if (data->full_buff[0] == '\0')
		data->valid_line = NULL;
	else
	{
		data->valid_line = ft_strndup(data->full_buff,
				ft_strlen(data->full_buff));
		if (!data->valid_line)
			return (ft_clear_struct(data));
	}
	ft_freestr(data->full_buff);
	return (data);
}

void	*ft_parse_line(int fd, t_buff *data)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*post_nl;

	post_nl = NULL;
	while (data->read_value >= 0 && !post_nl)
	{
		post_nl = ft_strchr(data->full_buff, '\n');
		if (post_nl)
			break ;
		data->read_value = read(fd, buffer, BUFFER_SIZE);
		if (data->read_value >= 0)
			buffer[data->read_value] = '\0';
		if (data->read_value <= 0)
			break ;
		data->full_buff = ft_stradd(data->full_buff, buffer);
		if (!data->full_buff)
			break ;
	}
	if (data->read_value < 0)
		return (ft_freestr(data->full_buff));
	if (data->full_buff && data->read_value >= 0)
		ft_extract_line(data);
	else
		ft_freestr(data->full_buff);
	return (data);
}

char	*get_next_line(int fd)
{
	static char	*residual[MAX_FD];
	t_buff		data;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1)
	{
		residual[fd] = NULL;
		return (NULL);
	}
	ft_init_struct(&data, residual[fd]);
	ft_parse_line(fd, &data);
	residual[fd] = data.residual;
	return (data.valid_line);
}
