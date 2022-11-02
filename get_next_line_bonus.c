/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 08:53:19 by serhouni          #+#    #+#             */
/*   Updated: 2022/11/01 05:13:24 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*opti_strjoin(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

char	*next_line(char *buffer)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == 0)
	{
		free(buffer);
		return (0);
	}
	next = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (next == 0)
		return (0);
	i++;
	j = 0;
	while (buffer[i] != '\0')
		next[j++] = buffer[i++];
	free(buffer);
	return (next);
}

char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (*buffer == 0)
		return (0);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (line == 0)
		return (0);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*read_file(int fd, char *result)
{
	char	*buffer;
	int		byteread;

	if (result == 0)
		result = ft_calloc(1, sizeof(char));
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (buffer == 0)
		return (0);
	byteread = 1;
	while (byteread > 0)
	{
		byteread = read(fd, buffer, BUFFER_SIZE);
		buffer[byteread] = 0;
		result = opti_strjoin(result, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (buffer[fd] == 0)
		return (0);
	line = get_line(buffer[fd]);
	buffer[fd] = next_line(buffer[fd]);
	return (line);
}
