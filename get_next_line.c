/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:46:33 by tjun-yu           #+#    #+#             */
/*   Updated: 2023/11/16 21:17:32 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_list	*lines;
	t_list	*current;
	fd += 0;
	if ((lines = (t_list *)malloc(sizeof(t_list)))== NULL)
		return (NULL);
	lines = NULL;
	current = lines;
	current->next = NULL;
	while (current->next != NULL)
		current = current->next;
	return (NULL);
}
