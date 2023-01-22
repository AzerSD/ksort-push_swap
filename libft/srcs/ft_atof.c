/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:06:40 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:13:18 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

const char	*get_start(const char *str, int *sign)
{
	while ((*str >= 9 && *str <= 13 && *str != 0) || *str == ' ')
		str++;
	*sign = 1;
	if (*str == '-')
	{
		*sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	return (str);
}

double	ft_atof(const char *str)
{
	int		sign;
	int		afterdot;
	double	scale;
	double	number;

	str = get_start(str, &sign);
	afterdot = 0;
	scale = 1;
	number = 0;
	while ((*str >= '0' && *str <= '9' && *str != 0) || *str == '.')
	{
		if (afterdot)
		{
			scale = scale / 10.0;
			number += (*str - '0') * scale;
		}
		else if (*str == '.')
			afterdot = 1;
		else
			number = number * 10.0 + (*str - '0');
		str++;
	}
	number *= (double) sign;
	return (number);
}
