/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:08:38 by kshoma            #+#    #+#             */
/*   Updated: 2023/09/25 13:48:55 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	unsigned char		*text;
	unsigned const char	*text2;
	unsigned int		num;

	if (buf1 == buf2 || !ft_memcmp(buf1, buf2, n) || !n)
		return (buf1);
	text = (unsigned char *)buf1;
	text2 = (unsigned const char *)buf2;
	num = 0;
	while (num < n)
	{
		text[num] = text2[num];
		num++;
	}
	return (buf1);
}
