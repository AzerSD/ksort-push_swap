/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:11:16 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:11:17 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	end;

	if (!str)
		return (NULL);
	while (ft_strchr(set, *str) && *str)
		str++;
	if (!*str)
		return (ft_strdup(""));
	end = ft_strlen(str);
	while (ft_strrchr(set, str[end]) && end > 0)
		end--;
	return (ft_substr(str, 0, end + 1));
}
