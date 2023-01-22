/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:10:03 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:10:04 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int32_t	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	if (ft_strlen(str1) != ft_strlen(str2))
		return (-1);
	while ((uint8_t)str1[i] && (uint8_t)str2[i] && \
			(uint8_t)str1[i] == (uint8_t)str2[i])
		i++;
	return ((uint8_t)str1[i] - (uint8_t)str2[i]);
}
