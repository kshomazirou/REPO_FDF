/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:42:11 by kshoma            #+#    #+#             */
/*   Updated: 2023/10/17 10:44:38 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_operator(char type, va_list args)
{
	size_t	len;

	len = 0;
	if (type == 'c')
		len = ft_putputchar_fd(va_arg(args, int));
	else if (type == 's')
		len = ft_putputstr_fd(va_arg(args, char *));
	else if (type == 'p')
		len = ft_pointer((unsigned long long)va_arg(args, void *));
	else if (type == 'd' || type == 'i')
		len = ft_inter(va_arg(args, int));
	else if (type == 'u')
		len = ft_uniter((unsigned int)va_arg(args, unsigned int));
	else if (type == 'x')
		len = ft_hexer(va_arg(args, unsigned int), 1);
	else if (type == 'X')
		len = ft_hexer(va_arg(args, unsigned int), 2);
	else if (type == '%')
		len = ft_putstr_count("%");
	return (len);
}
