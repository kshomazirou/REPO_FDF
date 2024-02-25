/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:23:49 by kshoma            #+#    #+#             */
/*   Updated: 2023/10/17 10:43:47 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include "ft_printf.h"
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>

int		ft_printf(char const *str, ...);

int		ft_putputchar_fd(char c);
char	*ft_point_base(unsigned long long point, int base);
int		ft_hexer(unsigned int i, int f);
int		ft_inter(int i);
int		ft_operator(char type, va_list args);
int		ft_pointer(unsigned long long pointer);
int		ft_putputstr_fd(char *str);
int		ft_putstr_count(char *c);
char	*ft_tolower_all(char *c);
int		ft_uniter(unsigned int unint);
#endif
