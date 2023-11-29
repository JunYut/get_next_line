/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:46:33 by tjun-yu           #+#    #+#             */
/*   Updated: 2023/11/29 17:14:40 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	*buffer;
	int		i;

	if ((line = (char *)malloc(BUFFER_SIZE + 1)) == NULL)
		return (NULL);
	read(fd, line, BUFFER_SIZE);
	line[BUFFER_SIZE] = 0;
	i = 2;
	while (is_line(line) == -1)
	{
		buffer = ft_strdup(line);
		free(line);
		if ((line = (char *)malloc(i * BUFFER_SIZE + 1)) == NULL)
			return (NULL);
		ft_strcpy(line, buffer);
		free(buffer);
		if ((buffer = (char *)malloc(BUFFER_SIZE + 1)) == NULL)
			return (NULL);
		read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = 0;
		// append buffer to line
		free(buffer);
		++i;
	}
	buffer = (char *)malloc(is_line(line) + 2);
	put_line(buffer, line);
	buffer[is_line(buffer)] = '\n';
	buffer[ft_strlen(buffer)] = 0;
	return (line);
}

static int	is_line(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != 0)
		if (str[i] == '\n')
			return (i);
	return (-1);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		++i;
	return (i);
}

static char	*ft_strdup(char *src)
{
	char	*new_str;
	int		i;

	if ((new_str = (char *)malloc(ft_strlen(src) + 1)) == NULL)
		return (NULL);
	i = -1;
	while (src[++i] != 0)
		new_str[i] = src[i];
	new_str[i] = 0;
	return (new_str);
}

static void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i] != 0)
		dest[i] = src[i];
	dest[i] = 0;
}

static void	put_line(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i] != '\n')
		dest[i] = src[i];
	dest[i] = '\n';
	dest[i + 1] = 0;
}
