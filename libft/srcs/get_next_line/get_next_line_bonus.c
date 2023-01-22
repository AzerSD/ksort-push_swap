/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:03:59 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:04:01 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include "get_next_line_utils.c"
// #include <stdio.h>

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
	ssize_t		buflen;
	size_t		linelen;

	linelen = 0;
	while (line[linelen] != '\n' && line[linelen])
		linelen++;
	if (line[linelen] == '\n')
		linelen++;
	buflen = (gnl_strlen(line) - linelen);
	if (buflen != 0)
		gnl_strlcpy(remainder, line + linelen, buflen + 1);
	else
		remainder[0] = '\0';
	line = gnl_substr(line, 0, linelen + 1);
	return (line);
}

/**
 * @brief Reads BUFFER_SIZE amount of chars every loop until finding a '\\n'
 * and appends this from buf to line each time.
 * ex BUFFER_SIZE = 11: 
 * loop 1: Buf = "Something i". Line = "Something i"
 * loop 2: Buf = "s here\\nAnd" Line = "Something is here\\nAnd"
 */
static char	*read_line(char	*line, char *buf, int fd)
{
	ssize_t		buflen;

	while (!(gnl_strchr(buf, '\n')))
	{
		buflen = read(fd, buf, BUFFER_SIZE);
		if (buflen <= 0 && !line[0])
		{
			free (line);
			return (NULL);
		}
		buf[buflen] = '\0';
		line = gnl_strjoin(line, buf);
		if (buflen < BUFFER_SIZE && !(gnl_strchr(buf, '\n')))
			return (line);
	}
	return (line);
}

/**
 * @brief Get the next line of a file every time the function is called.
 * line 	 - will hold the line to be returned (including '\\n' if available)
 * buf 		 - temporary storage for BUFFER_SIZE amount of chars 
 * remainder - Holds the remainder of the line after '\\n' 
 * (remainder is the same variable as buf but renamed in ft_trim)
 */
char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf[1024];

	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (!buf[fd])
		line = gnl_strjoin(line, buf[fd]);
	line = read_line(line, buf[fd], fd);
	if (!line)
		return (NULL);
	line = ft_trim(line, buf[fd]);
	return (line);
}

// int	main(void)
// {
// 	int		fd[3];
// 	size_t	i;
// 	char	*line;

// 	fd[0] = open("41_no_nl", 0);
// 	fd[1] = open("multiple_nlx5", 0);
// 	fd[2] = open("test.txt", 0);
// 	while (i < 4)
// 	{
// 		line = get_next_line(fd[i]);
// 		printf("%s", line);
// 		if (!line)
// 			i++;
// 	}
// 	free(line);
// 	close(fd);
// 	return (0);
// }
