/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fgets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 05:31:19 by asioud            #+#    #+#             */
/*   Updated: 2023/01/21 13:42:22 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_fgets(char **line)
{
	char	*buff;
	char	input;
	int		cnt;
	int		i;

	i = 0;
	buff = (char *)malloc(BUFFER_SIZE);
	if (!buff)
		return (-1);
	cnt = read(0, &input, 1);
	while (cnt && input != '\n' && input != '\0')
	{
		if (input != '\n' && input != '\0')
			buff[i] = input;
		i++;
		cnt = read(0, &input, 1);
	}
	buff[i] = '\n';
	buff[++i] = '\0';
	*line = ft_strdup(buff);
	return (free(buff), i);
}
