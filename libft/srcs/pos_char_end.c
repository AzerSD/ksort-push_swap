/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_char_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:11:55 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:11:57 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * Finds the last occurance of char in the string 
 * and returns that position.
 */
size_t	pos_char_end(char *str, char n)
{
	size_t	len;

	len = ft_strlen(str) - 1;
	while (str[len] != n && len > 0)
		len--;
	return (len);
}
