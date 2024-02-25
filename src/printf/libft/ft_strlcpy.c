/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:11:22 by kshoma            #+#    #+#             */
/*   Updated: 2023/09/25 11:14:37 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	num;

	num = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (src[num] != '\0' && n - 1 > num)
	{
		dest[num] = src[num];
		num++;
	}
	if (num < n)
		dest[num] = '\0';
	while (src[num] != '\0')
		num++;
	return (num);
}
