/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getncount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:11:50 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:11:51 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	getncount(char *str, uint8_t n)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str == n)
			count++;
		str++;
	}
	return (count);
}
