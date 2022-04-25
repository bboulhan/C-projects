/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:58:22 by bboulhan          #+#    #+#             */
/*   Updated: 2021/12/15 19:14:58 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*mallcpy(char *source, char *del)
{
	char	*s;
	int		i;

	free(del);
	if (!source)
		return (NULL);
	i = ft_strlen(source);
	s = (char *)ft_calloc(i + 1, 1);
	if (!s)
		return (NULL);
	i = -1;
	while (source[++i])
		s[i] = source[i];
	s[i] = 0;
	return (s);
}

int	ft_end(char *s, int k)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	if (k < BUFFER_SIZE && i > 0)
		return (i);
	return (-1);
}

char	*print_the_line(char *buffer, char *line, int fd)
{
	static char	*rest[1024];
	int			i;

	i = BUFFER_SIZE;
	if (rest[fd])
		line = mallcpy(rest[fd], line);
	while (i > 0 && read(fd, NULL, 0) >= 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		buffer[i] = 0;
		line = ft_strjoin(line, buffer);
		if (ft_end(line, i) != -1)
		{
			rest[fd] = mallcpy(ft_strchr(line, '\n'), rest[fd]);
			line = ft_substr(line, 0, ft_end(line, i) + 1);
			free(buffer);
			return (line);
		}
	}
	free(buffer);
	free(line);
	free(rest[fd]);
	rest[fd] = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;

	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	line = ft_calloc(1, 1);
	if (!line)
		return (NULL);
	return (print_the_line(buffer, line, fd));
}
