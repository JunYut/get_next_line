/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tanjunyu8888@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:46:33 by tjun-yu           #+#    #+#             */
/*   Updated: 2023/12/06 15:59:07 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	is_line(const char *str);
static char	*put_line(const char *buffer, int is_eof);
static int	read_line(int fd, char **buffer);
static char	*remove_line(char **buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			is_eof;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buffer, 0) < 0)
		return (NULL);
	if (buffer == NULL)
	{
		buffer = (char *)malloc(1);
		if (buffer == NULL)
			return (NULL);
		*buffer = 0;
	}
	is_eof = read_line(fd, &buffer);
	line = put_line(buffer, is_eof);
	buffer = remove_line(&buffer);
	if (is_eof == 0)
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}

static int	is_line(const char *str)
{
	int	i;

	i = -1;
	while (str[++i] != 0)
		if (str[i] == '\n')
			return (i);
	return (-1);
}

static char	*put_line(const char *buffer, int is_eof)
{
	char	*line;
	char	delimiter;
	int		i;

	if (is_eof != 0)
	{
		delimiter = '\n';
		line = (char *)malloc(is_line(buffer) + 2);
	}
	else
	{
		delimiter = 0;
		line = (char *)malloc(ft_strlen(buffer) + 1);
	}
	if (line == NULL)
		return (NULL);
	i = -1;
	while (buffer[++i] != delimiter)
		line[i] = buffer[i];
	line[i] = delimiter;
	if (is_eof != 0)
		line[i + 1] = 0;
	return (line);
}

static int	read_line(int fd, char **buffer)
{
	char	*temp;
	int		bytes_read;

	bytes_read = 404;
	while (is_line(*buffer) == -1 && bytes_read != 0)
	{
		temp = (char *)malloc(BUFFER_SIZE + 1);
		if (temp == NULL)
			return (-1);
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (bytes_read);
		if (bytes_read != BUFFER_SIZE)
			temp[bytes_read] = 0;
		else
			temp[BUFFER_SIZE] = 0;
		*buffer = ft_strjoin(buffer, temp);
		free(temp);
	}
	return (bytes_read);
}

static char	*remove_line(char **buffer)
{
	char	*next_line;
	int		i;
	int		j;

	i = is_line(*buffer) + 1;
	next_line = (char *)malloc(ft_strlen(*buffer + i) + 1);
	if (next_line == NULL)
		return (NULL);
	j = -1;
	while (*(*buffer + i) != 0)
	{
		next_line[++j] = *(*buffer + i);
		++i;
	}
	next_line[j + 1] = 0;
	free(*buffer);
	return (next_line);
}
