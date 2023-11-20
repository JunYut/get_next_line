/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tanjunyu8888@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:30:11 by tjun-yu           #+#    #+#             */
/*   Updated: 2023/11/20 16:03:47 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newline_pos(char *str)
{
	int	position;

	position = 0;
	while (str[position] != 0)
	{
		if (str[position] == '\n')
			return (position);	
		++position;
	}
	return (-1);
}

static int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
		++len;
	return (len);
}

char	*ft_strdup(char *org)
{
	char	*duplicate;
	int		i;

	duplicate = (char *)malloc((ft_strlen(org) + 1) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);
	i = -1;
	while (org[++i] != 0)
		duplicate[i] = org[i];
	duplicate[i] = 0;
	return (duplicate);
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	copy_len;
	int		i;

	if (dest == NULL && size == 0)
		return (0);
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	copy_len = size - dest_len - 1;
	i = -1;
	if (dest == 0)
		return (src_len);
	if (size <= dest_len)
		return (src_len + size);
	if (copy_len < src_len)
		while (++i < (int)copy_len)
			dest[dest_len + i] = src[i];
	else
		while (src[++i] != 0)
			dest[dest_len + i] = src[i];
	dest[dest_len + i] = 0;
	return (dest_len + src_len);
}

char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	if ((line = (char *)malloc(newline_pos(buffer) + 1 + 1)) == NULL)
		return (NULL);
	i = -1;
	while (buffer[++i] != '\n')
		line[i] = buffer[i];
	buffer[i] = '\n';
	buffer[i + 1] = 0;
	return (line);
}
