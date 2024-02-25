/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:06:53 by kshoma            #+#    #+#             */
/*   Updated: 2023/09/25 10:39:57 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t			num;
	unsigned char	*text;
	unsigned char	val;

	num = 0;
	text = (unsigned char *)buf;
	val = (unsigned char )ch;
	while (num < n)
	{
		text[num] = val;
		num++;
	}
	return (buf);
}
