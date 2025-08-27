/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafroidu <pafroidu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:38:36 by pafroidu          #+#    #+#             */
/*   Updated: 2025/07/25 00:36:25 by pafroidu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 	-- read from a file descriptor line by line, storing what we didn't display
	in a static buffer (rest) and returning one line per call --

	--------------------------------------------------------------

	get_next_line + read until new line (because of the norm):
	static variable are initialised to NULL by default by the compilator
		variables
		- rest = static buffer storing leftover data from the previous call
		- buffer = temporary chunk read from the file (of BUFFER_SIZE)
		- bytes_read = result of read() - can be negative on error (ssize_t !)
		- line = the line to return

		logic
		1. While there is no '\n' in rest str:
		- read a BUFFER_SIZE chunk
		- append it to rest

		2. If a '\n' was found or EOF is reached:
		- extract the line up to and including '\n'
		- update rest to keep everything after '\n'

		--------------------------------------------------------------

	extract_line :
		- iterate through rest until we reach '\0' or '\n'
		- if '\n' is found, include it (+1) in allocation
		- allocate a new string and copy that segment
		- return the substring as the line

		--------------------------------------------------------------

	update_rest :
	- search for '\n' in rest
	- if not found (meaning : rest[i] == '\0'): free rest and return NULL
	- else:
		- move index past '\n'
		- allocate a new string with everything after '\n'
		- copy it and free the old rest
		- return the updated rest */

#include "get_next_line.h"

char	*extract_line(char *rest)
{
	size_t	i;
	char	*extracted_str;

	i = 0;
	while (rest[i] != '\0' && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		i++;
	extracted_str = malloc(sizeof(char) * (i + 1));
	if (!extracted_str)
		return (NULL);
	ft_strcpy_gnl(extracted_str, rest, i);
	return (extracted_str);
}

char	*update_rest(char *rest)
{
	size_t	i;
	char	*updated_str;

	i = 0;
	while (rest[i] != '\0' && rest[i] != '\n')
		i++;
	if (rest[i] == '\0')
	{
		free(rest);
		return (NULL);
	}
	i++;
	updated_str = malloc(sizeof(char) * (ft_strlen_gnl(rest + i) + 1));
	if (!updated_str)
		return (NULL);
	ft_strcpy_gnl(updated_str, rest + i, ft_strlen_gnl(rest + i));
	free (rest);
	return (updated_str);
}

char	*ft_read_until_newline(int fd, char *rest)
{
	ssize_t		bytes_read;
	char		*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr_gnl(rest, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(rest), (NULL));
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		rest = ft_strjoin_gnl(rest, buffer);
		if (!rest)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!rest)
		rest = ft_strdup_gnl("");
	rest = ft_read_until_newline(fd, rest);
	if (!rest || rest[0] == '\0')
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	line = extract_line(rest);
	rest = update_rest(rest);
	return (line);
}
