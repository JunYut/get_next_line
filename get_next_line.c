/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tanjunyu8888@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:46:33 by tjun-yu           #+#    #+#             */
/*   Updated: 2023/11/20 16:03:37 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		buffer_size;
	char	*buffer;
	char	*line;
	int		bytes_read;

	buffer_size = BUFFER_SIZE;
	buffer = (char *)malloc(buffer_size + 1);
	if ((bytes_read = read(fd, buffer, BUFFER_SIZE)) == -1)
		return (NULL);
	buffer[bytes_read] = 0;
	while (newline_pos(buffer) == -1)
	{
		line = ft_strdup(buffer);
		free(buffer);
		buffer_size += BUFFER_SIZE;
		if ((buffer = (char *)malloc(buffer_size + 1)) == NULL)
			return (NULL);
		ft_strlcat(buffer, line, buffer_size + 1);
		free(line);
		if ((bytes_read += read(fd, buffer + bytes_read, BUFFER_SIZE)) == -1)
			return (NULL);
		buffer[bytes_read] = 0;
	}
	return (extract_line(buffer));
}
