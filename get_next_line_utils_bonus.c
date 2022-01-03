/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:56:39 by zcherrad          #+#    #+#             */
/*   Updated: 2022/01/03 19:56:46 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		line = (char *)malloc(sizeof(char) * i + 2);
	else
		line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		line[i] = str[i];
	if (str[i] != '\n')
		line[i] = '\0';
	else
	{
		line[i] = '\n';
		line[++i] = '\0';
	}
	return (line);
}

char	*get_rest(char *str)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	while (str[i] != '\0')
		rest[j++] = str[i++];
	rest[j] = str[i];
	free(str);
	return (rest);
}

char	*ft_strjoin(char *str, char *buff)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!str)
	{
		str = (char *) malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	dest = (char *)malloc((ft_strlen(str) + ft_strlen(buff) + 1));
	if (!dest)
		return (NULL);
	while (str[++i] != '\0')
		dest[i] = str[i];
	while (buff[++j] != '\0')
		dest[i + j] = buff[j];
	dest[i + j] = '\0';
	free(str);
	return (dest);
}
