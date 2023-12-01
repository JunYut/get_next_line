/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tanjunyu8888@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:46:33 by tjun-yu           #+#    #+#             */
/*   Updated: 2023/12/01 15:46:16 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int 	is_line(const char *str);
static char	*put_line(const char *buffer, int is_eof);
static int	read_line(int fd, char **buffer);
static char	*remove_line(char **buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			is_eof;

	if (buffer == NULL)
	{
		if ((buffer = (char *)malloc(1)) == NULL)
			return (NULL);
		*buffer = 0;
	}
	// printf("\nread_line->\n------------------\n");
	is_eof = read_line(fd, &buffer);
	// printf("is_eof: %d\n", is_eof);
	
	// printf("\nput_line->\n------------------\n");
	line = put_line(buffer, is_eof);
	
	// printf("\nremove_line->\n------------------\n");
	buffer = remove_line(&buffer);
	//printf("next_line: %s", buffer);
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
	int		i;

	i = -1;
	if (is_eof != 0)
	{
		if ((line = (char *)malloc(is_line(buffer) + 2)) == NULL)
			return (NULL);
		while (buffer[++i] != '\n')
			line[i] = buffer[i];
		line[i] = '\n';
		line[i + 1] = 0;
	}
	else
	{
		if ((line = (char *)malloc(ft_strlen(buffer))) == NULL)
			return (NULL);
		while (buffer[++i] != 0)
			line[i] = buffer[i];
		line[i] = 0;
	}
	return (line);
}

static int read_line(int fd, char **buffer)
{
	char	*temp;
	int		bytes_read;

	bytes_read = 404;
	while (is_line(*buffer) == -1 && bytes_read != 0)
	{
		// printf(" is_line: %d\n", is_line(*buffer));
		// printf("bytes_read: %d\n", bytes_read);
		if ((temp = (char *)malloc(BUFFER_SIZE + 1)) == NULL)
			return (-1);
		if ((bytes_read = read(fd, temp, BUFFER_SIZE)) == -1)
			return (bytes_read);
		temp[BUFFER_SIZE] = 0;
		*buffer = ft_strjoin(buffer, temp);
		printf("buffer: %s\n", *buffer);
		free(temp);
	}
	return (bytes_read);
}

static char	*remove_line(char **buffer)		// buffer cleaning oversight, causing corrupted buffer
{
	char	*next_line;
	int		i;
	int		j;

	i = is_line(*buffer) + 1;
	if ((next_line = (char *)malloc(ft_strlen(*buffer + i) + 1)) == NULL)
		return (NULL);
	j = -1;
	while (*(*buffer + i) != 0)
	{
		printf("char: %c", *(*buffer + i));
		next_line[++j] = *(*buffer + i++);
	}
	next_line[j] = 0;
	free(*buffer);
	return (next_line);
}
