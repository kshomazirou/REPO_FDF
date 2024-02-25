/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:35:46 by kshoma            #+#    #+#             */
/*   Updated: 2023/09/25 09:04:52 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	size_t	len;
	size_t	i;
	char	*buffer;

	i = 0;
	len = ft_strlen(string);
	buffer = (char *)malloc(len + 1);
	if (buffer == NULL)
		return (NULL);
	while (i < len)
	{
		buffer[i] = string[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
