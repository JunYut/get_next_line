/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tanjunyu8888@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:46:33 by tjun-yu           #+#    #+#             */
/*   Updated: 2023/11/15 15:51:08 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_lines	*lines;

	lines = (t_lines *)malloc(sizeof(t_lines));
	if (lines == NULL)
		return (NULL);
	lines->line = NULL;
	lines->next = NULL;
	while (check_newline(lines->line) == -1)
	{
		append_node(lines);
		fill_line(lines, fd);
	}
	return (lines->line);
}
