/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:09:16 by kshoma            #+#    #+#             */
/*   Updated: 2023/09/26 09:24:12 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	unsigned char		*text;
	unsigned const char	*text2;

	text = (unsigned char *)buf1;
	text2 = (const unsigned char *)buf2;
	if (text == text2 || n == 0)
		return (buf1);
	if (text < text2)
	{
		while (n-- > 0)
			*text++ = *text2++;
	}
	else
	{
		text += n;
		text2 += n;
		while (n-- > 0)
			*(--text) = *(--text2);
	}
	return (buf1);
}
