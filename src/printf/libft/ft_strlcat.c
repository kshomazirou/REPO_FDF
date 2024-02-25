/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:11:37 by kshoma            #+#    #+#             */
/*   Updated: 2023/09/25 11:15:37 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dnum;
	size_t	snum;
	size_t	cpy_size;
	size_t	i;

	dnum = 0;
	snum = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[dnum] != '\0' && dnum < size)
		dnum++;
	while (src[snum] != '\0')
		snum++;
	cpy_size = size - dnum - 1;
	if (size <= dnum)
		return (dnum + snum);
	i = 0;
	while (src[i] != '\0' && cpy_size > i)
	{
		dst[dnum + i] = src[i];
		i++;
	}
	dst[dnum + i] = '\0';
	return (dnum + snum);
}
