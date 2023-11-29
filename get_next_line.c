/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tanjunyu8888@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:46:33 by tjun-yu           #+#    #+#             */
/*   Updated: 2023/11/30 12:14:54 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int is_line(char *str);
static char *ft_strdup(char *src);
static void ft_strcpy(char *dest, char *src);
static void append(char *dest, char *src, int line_size);
static void put_line(char *dest, char *src);
static int ft_strlen(char *str);

char	*get_next_line(int fd)
{
	char	*line;
	char	*buffer;
	int		bytes_read;
	int		i;

	if ((line = (char *)malloc(BUFFER_SIZE + 1)) == NULL)
		return (NULL);
	bytes_read = read(fd, line, BUFFER_SIZE);
	line[bytes_read] = 0;
	i = 2;
	while (is_line(line) == -1 && bytes_read != 0)
	{
		buffer = ft_strdup(line);
		free(line);
		if ((line = (char *)malloc(i * BUFFER_SIZE + 1)) == NULL)
			return (NULL);
		ft_strcpy(line, buffer);
		free(buffer);
		if ((buffer = (char *)malloc(BUFFER_SIZE + 1)) == NULL)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
		append(line, buffer, i * BUFFER_SIZE);
		free(buffer);
		++i;
	}
	if (bytes_read == 0)
	{
		buffer = (char *)malloc(ft_strlen(line) + 1);
		ft_strcpy(buffer, line);
	}
	else
	{	
		buffer = (char *)malloc(is_line(line) + 2);
		put_line(buffer, line);
		buffer[ft_strlen(buffer) - 1] = '\n';
	}
	buffer[ft_strlen(buffer)] = 0;
	free(line);
	return (buffer);
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

static void	append(char *dest, char *src, int line_size)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != 0)
		++i;
	j = -1;
	while (i < line_size)
		dest[i++] = src[++j];
	dest[i] = 0;
}
