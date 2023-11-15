/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tanjunyu8888@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:21:41 by tjun-yu           #+#    #+#             */
/*   Updated: 2023/11/15 15:40:49 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(char *line)
{
	int	position;
	
	position = -1;
	while (line[++position] != 0)
		if (line[position] == '\n')
			return (position);
	return (-1);
}

void	append_node(t_lines *lines)
{
	t_lines	*new;
	t_lines	*current;

	new = (t_lines *)malloc(sizeof(t_lines));
	if (new == NULL)
		return ;
	new->line = NULL;
	new->next = NULL;
	current = lines;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

void	fill_line(t_lines *lines, int fd)
{
	lines->line = (char *)malloc(BUFFER_SIZE + 1);
	read(fd, lines->line, BUFFER_SIZE);
}
