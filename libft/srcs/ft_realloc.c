/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:09:48 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:09:49 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

void	*ft_realloc(void *ptr, size_t size)
{
	size_t	i;
	char	*out;

	i = 0;
	if (!ptr)
		return (NULL);
	out = malloc(size);
	if (!out)
		return (NULL);
	while (size-- > 0)
	{
		out[i] = ((uint8_t *)ptr)[i];
		i++;
	}
	return (out);
}
