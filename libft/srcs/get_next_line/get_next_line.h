/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:04:37 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:04:39 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/**
 * @brief Every time this function is called one line will be read
 * and every succeeding call, it will continue where it left off.
 * @param fd File descriptor being read from.
 * @return The next line to be read from the file descriptor.
 */
char		*get_next_line(int fd);

/** 
 * Checks the length of str.
 * @param str A string.
 * @return The length of the string.
 */
int			gnl_strlen(const char *str);

/**
 * Copies str to a new memory location and returns a pointer to that string.
 * @param str The string to be duplicated.
 * @return A pointer to a new memory location with the duplicated string.
 */
char		*gnl_strdup(char *str);

/**
 * Returns a pointer to the first occurance of c in str.
 * @param str String in which the character will be searched.
 * @param c Character to be searched for in the string.
 * @return A pointer to the first occurance of c in str.
 */
char		*gnl_strchr(const char *str, int32_t c);

/**
 * Allocates (with malloc(3)) and returns a new string, 
 * which is the result of the concatenation of `s1` and `s2`.
 * @param str1 The prefix string.
 * @param str2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */
char		*gnl_strjoin(char *str1, char *str2);

/**
 * Allocates (with malloc(3)) and returns a substring from the string `s`. 
 * The substring begins at index `start` and is of maximum size `len`.
 * @param str The string from which to create the substring.
 * @param start The start index of the substring in the string `s`.
 * @param len The maximum length of the substring.
 * @return The substring. NULL if the allocation fails.
 */
char		*gnl_substr(char *str, uint32_t start, size_t len);

/**
 * Copies up to size - 1 characters from the NUL-terminated 
 * string src to dst, NUL-terminating the result. as long as size 
 * is larger than 0. A byte for NUL 
 * should be included in size. Src must be NUL-terminated.
 * @param dest Where src is to be copied to.
 * @param src The string to be copied to dest.
 * @param size How many characters are to be copied.
 * @return The total length of the string it tried to create: 
 * the initial length of dst plus the length of src.
 */
size_t		gnl_strlcpy(char *dst, char *src, size_t size);

#endif