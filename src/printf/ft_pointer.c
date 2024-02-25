/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:46:26 by kshoma            #+#    #+#             */
/*   Updated: 2023/10/17 10:43:34 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long long pointer)
{
	char	*point;
	int		n;

	point = ft_tolower_all(ft_point_base(pointer, 16));
	n = ft_putstr_count("0x");
	n += ft_putstr_count(point);
	free(point);
	return (n);
}
