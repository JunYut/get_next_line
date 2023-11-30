/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tanjunyu8888@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:46:33 by tjun-yu           #+#    #+#             */
/*   Updated: 2023/11/30 15:56:26 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int 	is_line(const char *str);
static char	*put_line(const char *buffer);
static void	read_line(int fd, char *buffer);
static char	*remove_line(const char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	read_line(fd, buffer);
	line = put_line(buffer);
	buffer = remove_line(buffer);
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

static char	*put_line(const char *buffer)
{
	char	*line;
	int		i;

	if ((line = (char *)malloc(is_line(buffer) + 2)) == NULL)
		return (NULL);
	i = -1;
	while (buffer[++i] != '\n')
		line[i] = buffer[i];
	buffer[i] = '\n';
	buffer[i + 1] = 0;
	return (line);
}

static void read_line(int fd, char *buffer)
{
	char	*temp;
	int		bytes_read;

	*buffer = 0;
	bytes_read = 1;
	while (is_line(buffer) == -1 || bytes_read != 0)
	{
		if ((temp = (char *)malloc(BUFFER_SIZE + 1)) == NULL)
			return ;
		if (bytes_read = read(fd, temp, BUFFER_SIZE) == -1)
			return ;
		buffer = ft_strjoin(buffer, temp);
	}
}

static char	*remove_line(const char *buffer)
{
	char	*next_line;
	int		i;
	int		j;

	i = is_line(buffer);
	if ((next_line = (char *)malloc(ft_strlen(buffer[i]) + 1)) == NULL)
		return (NULL);
	j = -1;
	while (buffer[i] != 0)
		next_line[++j] = buffer[i++];
	next_line[j + 1] = 0;
	return (next_line);
}
