/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:08:50 by zcherrad          #+#    #+#             */
/*   Updated: 2022/01/03 19:57:24 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_all_line(int fd, char *str)
{
	int		byte;
	char	*buff;

	byte = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (byte != 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[byte] = '\0';
		str = ft_strjoin(str, buff);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*dest;
	static char	*str[10240];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = get_all_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	dest = get_line(str[fd]);
	str[fd] = get_rest(str[fd]);
	return (dest);
}
