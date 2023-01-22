/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:04:17 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:04:19 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = gnl_strlen((char *)src);
	i = 0;
	if (size == 0)
		return (len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	return (len);
}

char	*gnl_strdup(char *str)
{
	size_t	len;
	char	*out;

	len = gnl_strlen((char *)str) + 1;
	out = malloc(len * sizeof(char));
	if (!out)
		return (NULL);
	gnl_strlcpy(out, str, len + 1);
	free (str);
	return (out);
}

char	*gnl_strchr(const char *str, int32_t c)
{
	char	*str2;

	if (!str)
		return (NULL);
	if (c < 0 || c > 255)
		return ((char *)str);
	str2 = (char *)str;
	while (*str2 != c && *str2)
		str2++;
	if (*str2 == c)
		return (str2);
	return (0);
}

char	*gnl_strjoin(char *str1, char *str2)
{
	size_t	str1len;
	size_t	str2len;
	char	*out;

	if (!str1 || !str2)
		return (0);
	str1len = gnl_strlen(str1);
	str2len = gnl_strlen(str2);
	out = malloc((str1len + str2len + 1) * sizeof(char));
	if (!out)
		return (0);
	gnl_strlcpy(out, str1, str1len + 1);
	free(str1);
	gnl_strlcpy(out + str1len, str2, str2len + 1);
	return (out);
}

char	*gnl_substr(char *str, uint32_t start, size_t len)
{
	char	*out;
	size_t	slen;

	slen = gnl_strlen(str);
	if (!str)
		return (NULL);
	if (start >= slen)
		return (gnl_strdup(""));
	if (len > slen - start)
		return (gnl_strdup(str + start));
	out = malloc((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	gnl_strlcpy(out, str + start, len);
	free(str);
	out[len] = '\0';
	return (out);
}
