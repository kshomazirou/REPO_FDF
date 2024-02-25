/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:32:06 by kshoma            #+#    #+#             */
/*   Updated: 2023/09/25 16:57:32 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	nlen;

	n = 0;
	nlen = ft_strlen(needle);
	if (needle == NULL || nlen == 0)
		return ((char *)haystack);
	while (n < len && haystack[n])
	{
		if (ft_strncmp((char *)&haystack[n], needle, nlen) == 0)
		{
			if (n + nlen <= len)
				return ((char *)&haystack[n]);
			else
				return (NULL);
		}
		n++;
	}
	return (NULL);
}
