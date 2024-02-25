/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:33:18 by kshoma            #+#    #+#             */
/*   Updated: 2023/09/25 17:38:44 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	num;

	num = 0;
	while (n > num && (s1[num] != '\0' || s2[num] != '\0'))
	{
		if ((unsigned char)s1[num] != (unsigned char)s2[num])
			return ((unsigned char)s1[num] - (unsigned char)s2[num]);
		num++;
	}
	return (0);
}
