/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uber_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:48:00 by kshoma            #+#    #+#             */
/*   Updated: 2023/10/17 10:45:02 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_uber_count(unsigned int u, size_t t)
{
	char			str;
	unsigned int	temp;

	temp = u;
	while (9 < temp)
	{
		temp = temp / 10;
		t++;
	}
	if (9 < u)
		ft_uber_count(u / 10, t);
	str = '0' + u % 10;
	write(1, &str, 1);
	return (t + 1);
}

int	ft_uniter(unsigned int unint)
{
	int	n;

	n = 0;
	n = ft_uber_count(unint, 0);
	return (n);
}
