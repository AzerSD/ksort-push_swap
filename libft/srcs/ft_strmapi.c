/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:10:55 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:10:57 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *str, char (*f)(uint32_t, char))
{
	size_t	i;
	char	*out;

	i = 0;
	if (!str)
		return (NULL);
	out = malloc(ft_strlen((char *)str) + 1 * sizeof(char));
	if (!out)
		return (NULL);
	while (str[i])
	{
		out[i] = f(i, str[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
