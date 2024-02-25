/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:30:33 by kshoma            #+#    #+#             */
/*   Updated: 2023/09/26 16:32:23 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	num;

	num = ft_strlen(s);
	while (num >= 0)
	{
		if (s[num] == (char)c)
			return ((char *)&s[num]);
		num--;
	}
	return (NULL);
}
