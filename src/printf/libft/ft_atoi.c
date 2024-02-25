/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:34:52 by kshoma            #+#    #+#             */
/*   Updated: 2023/10/02 11:04:35 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	judge(int s, long int n, int now)
{
	if (s == 1 && ((LONG_MAX / 10 < n) || (LONG_MAX - n * 10 - now <= 0)))
		return (1);
	if (s == -1 && ((LONG_MIN / 10 > n) || (LONG_MIN + n * 10 + now >= 0)))
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long int	result;
	int			num;
	int			sign;

	result = 0;
	num = 0;
	sign = 1;
	while ((str[num] >= '\t' && str[num] <= '\r') || str[num] == ' ')
		num++;
	if (str[num] == '-' || str[num] == '+')
	{
		if (str[num] == '-')
			sign = -1;
		num++;
	}
	while (str[num] >= '0' && str[num] <= '9')
	{
		if (judge(sign, result, str[num] - '0') == 1)
			return ((int)LONG_MAX);
		if (judge(sign, result, str[num] - '0') == -1)
			return ((int)LONG_MIN);
		result = result * 10 + (str[num] - '0');
		num++;
	}
	return ((int)result * sign);
}
