/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_char_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:12:00 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:12:02 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * Finds the first occurance of char in the string 
 * and returns that position.
 */
size_t	pos_char_start(char *str, char n)
{
	size_t	len;

	len = 0;
	while (str[len] != n && str[len])
		len++;
	return (len);
}
