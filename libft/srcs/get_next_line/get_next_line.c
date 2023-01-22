/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:04:30 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:04:32 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include "get_next_line_utils.c"

/**
 * example .txt file in my further comments:
 * "Something is here"
 * "And something else"
 */
int	gnl_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * @brief Trims everything after a newline char into the remainder 
 * and the rest into line.
 * example: line = "Something is here\\nAnd" 
 * Result:
 * line = "Something is here\\n"
 * remainder = "And"
 */
static char	*ft_trim(char *line, char *remainder)
{
	ssize_t		remdrlen;
	size_t		linelen;

	linelen = 0;
	while (line[linelen] != '\n' && line[linelen])
		linelen++;
	if (line[linelen] == '\n')
		linelen++;
	remdrlen = (gnl_strlen(line) - linelen);
	if (remdrlen != 0)
		gnl_strlcpy(remainder, line + linelen, remdrlen + 1);
	else
		remainder[0] = '\0';
	return (gnl_substr(line, 0, linelen + 1));
}

/**
 * @brief Reads BUFFER_SIZE amount of chars every loop until finding a '\\n'
 * and appends this from buf to line each time.
 * example BUFFER_SIZE = 11: 
 * loop 1: Buf = "Something i". Line = "Something i"
 * loop 2: Buf = "s here\\nAnd" Line = "Something is here\\nAnd"
 */
static char	*read_line(char *line, char *buf, int fd)
{
	ssize_t		buflen;

	buflen = BUFFER_SIZE;
	while (!(gnl_strchr(buf, '\n')) && buflen == BUFFER_SIZE)
	{
		buflen = read(fd, buf, BUFFER_SIZE);
		buf[buflen] = '\0';
		if (buflen <= 0 && !line[0])
		{
			free (line);
			return (NULL);
		}
		line = gnl_strjoin(line, buf);
	}
	return (line);
}

/**
 * @brief Get the next line of a file every time the function is called.
 * Appends the remainder from the previous function call to line if present.
 * line 	 - will hold the line to be returned (including '\\n' if available)
 * buf 		 - temporary storage for BUFFER_SIZE amount of chars 
 * remainder - Holds the remainder of the line after '\\n' 
 * (remainder is the same variable as buf but renamed in ft_trim)
 */
char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[BUFFER_SIZE + 1];

	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (buf[0] != '\0')
		line = gnl_strjoin(line, buf);
	line = read_line(line, buf, fd);
	if (!line)
		return (NULL);
	line = ft_trim(line, buf);
	return (line);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("41_no_nl", 0);
// 	if (!fd)
// 		return (0);
// 	while (1 == 1)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		if (!line)
// 			break ;
// 	}
// 	close(fd);
// 	return (0);
// }
