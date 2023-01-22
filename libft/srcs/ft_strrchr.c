/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:11:11 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:11:13 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *str, int32_t c)
{
	int32_t	len;
	char	*str2;

	len = ft_strlen((char *)str);
	str2 = (char *)str + len;
	if (!ft_isascii(c))
		return ((char *)str);
	while (len-- >= 0)
	{
		if (*str2 == c)
			return (str2);
		str2--;
	}
	return (0);
}
