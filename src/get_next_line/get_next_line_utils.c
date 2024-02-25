/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:09:59 by kshoma            #+#    #+#             */
/*   Updated: 2023/11/20 19:50:59 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	num;

	num = 0;
	while (str[num] != '\0')
		num++;
	return (num);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	size_t	len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = 0;
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

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
	ft_memset(box, 0, n * size);
	return (box);
}
