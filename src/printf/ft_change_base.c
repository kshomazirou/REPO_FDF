/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:43:20 by kshoma            #+#    #+#             */
/*   Updated: 2023/10/17 10:44:28 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*change_base(unsigned long long us, int b, char *v, int c)
{
	while (us != 0)
	{
		if ((us % b) < 10)
			v[c - 1] = (us % b) + 48;
		else
			v[c - 1] = (us % b) + 55;
		us = us / b;
		c--;
	}
	return (v);
}

char	*ft_point_base(unsigned long long point, int base)
{
	char				*value;
	unsigned long long	us;
	int					count;

	count = 0;
	us = point;
	if (point == 0)
		return (ft_strdup("0"));
	while (point != 0)
	{
		point = point / base;
		count++;
	}
	value = ft_calloc(count + 1, sizeof(char));
	if (!value)
		return (0);
	value = change_base(us, base, value, count);
	return (value);
}
