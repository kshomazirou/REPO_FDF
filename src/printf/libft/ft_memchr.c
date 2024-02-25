/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:10:03 by kshoma            #+#    #+#             */
/*   Updated: 2023/09/25 09:09:35 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	size_t				num;
	const unsigned char	*text;

	text = (const unsigned char *)buf;
	num = 0;
	while (n > num)
	{
		if (text[num] == (unsigned char)ch)
			return ((void *)&text[num]);
		num++;
	}
	return (NULL);
}
