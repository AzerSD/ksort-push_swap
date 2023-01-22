/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_ignore.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:10:47 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:10:48 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strlen_ignore(const char *str, char ignore)
{
	int32_t	i;
	int32_t	minus;

	i = 0;
	minus = 0;
	while (str[i] != '\0')
	{
		if (str[i++] == ignore)
			minus++;
	}
	return (i - minus);
}
