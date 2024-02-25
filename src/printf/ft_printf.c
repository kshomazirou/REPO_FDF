/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:22:58 by kshoma            #+#    #+#             */
/*   Updated: 2023/10/17 10:44:45 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *line, ...)
{
	va_list	args;
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, line);
	while (line[i])
	{
		if (line[i] == '%')
			len += ft_operator(line[++i], args);
		else
		{
			ft_putchar_fd(line[i], 1);
			len++;
		}
		i++;
		if (!line[i])
			break ;
	}
	va_end(args);
	return (len);
}
