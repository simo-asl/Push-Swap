/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:16:23 by mel-asla          #+#    #+#             */
/*   Updated: 2025/11/11 19:17:57 by mel-asla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_helper(char *buffer, char *buf)
{
	char	*tmp;

	if (!buffer)
		tmp = ft_strdup(buf);
	else
	{
		tmp = ft_strjoin(buffer, buf);
		free(buffer);
	}
	return (tmp);
}

static char	*ft_read(int fd, char *buffer)
{
	char	*buf;
	ssize_t	bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buffer, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		buffer = ft_helper(buffer, buf);
	}
	free(buf);
	return (buffer);
}

static char	*ft_line(char *buffer)
{
	char	*line;
	size_t	i;

	if (!buffer || !buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_substr(buffer, 0, i + 1);
	else
		line = ft_substr(buffer, 0, i);
	return (line);
}

static char	*ft_buffering(char *buffer)
{
	char	*new_buffer;
	size_t	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_substr(buffer, i + 1, ft_strlen(buffer) - (i + 1));
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd, char **buffer)
{
	char	*line;

	if (!*buffer)
		*buffer = ft_strdup("");
	*buffer = ft_read(fd, *buffer);
	if (!*buffer)
		return (NULL);
	line = ft_line(*buffer);
	*buffer = ft_buffering(*buffer);
	return (line);
}
