/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:02:27 by zcherrad          #+#    #+#             */
/*   Updated: 2022/01/01 15:48:10 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdlib.h>
# include<unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

char	*ft_strchr(char *s, int c);

size_t	ft_strlen(char *str);

char	*get_all_line(int fd, char *str);

char	*get_line(char *str);

char	*get_next_line(int fd);

char	*ft_strjoin(char *str, char *buff);

char	*get_rest(char *str);
#endif
