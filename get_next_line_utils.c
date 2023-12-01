/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tanjunyu8888@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:01:31 by tjun-yu           #+#    #+#             */
/*   Updated: 2023/12/01 10:10:52 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *str1, const char *str2)
{
	char	*new_str;
	int		total_size;

	if (str1 == NULL)
		if ((str1 = (char *)malloc(1)) == NULL)
			return (NULL);
	total_size = ft_strlen(str1) + ft_strlen(str2);
	if ((new_str = (char *)malloc(total_size) + 1) == NULL)
		return (NULL);
	ft_memmove(new_str, str1, ft_strlen(str1));
	ft_memmove(new_str + ft_strlen(str1), str2, ft_strlen(str2));
	free(str1);
	new_str[total_size - 1] = 0;
	return (new_str);
}

char	*ft_memmove(char *dest, const char *src, int src_len)
{
	int	i;

	if (dest == NULL || src == NULL)
		return (NULL);
	i = src_len + 1;
	if (src < dest)
		while (--i > 0)
			dest[i - 1] = src[i - 1];
	else
	{
		i = -1;
		while (++i < src_len)
			dest[i] = src[i];
	}
	return (dest);
}

int		ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
		++len;
	return (len);
}
