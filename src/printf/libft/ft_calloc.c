/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:35:22 by kshoma            #+#    #+#             */
/*   Updated: 2023/10/02 08:49:54 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*box;

	if (!n || !size)
	{
		n = 1;
		size = 1;
	}
	if (SIZE_MAX / n < size)
		return (malloc(SIZE_MAX));
	box = (void *)malloc(n * size);
	if (box == NULL)
		return (NULL);
	ft_bzero(box, n * size);
	return (box);
}
