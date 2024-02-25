/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:49:51 by kshoma            #+#    #+#             */
/*   Updated: 2023/10/17 10:44:33 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexer(unsigned int i, int f)
{
	char	*hex;
	int		n;

	if (!i)
		i = 0;
	hex = ft_point_base((unsigned long long)i, 16);
	if (f == 1)
		hex = ft_tolower_all(hex);
	n = ft_putstr_count(hex);
	free(hex);
	return (n);
}
