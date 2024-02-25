/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:45:05 by kshoma            #+#    #+#             */
/*   Updated: 2024/02/24 11:22:23 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_data(t_fdf data)
{
	char	*menu;

	menu = "up, down, left, right: move picture";
	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, 5, 0x03fc35, menu);
	menu = "5, space: 3d/2d mode; +, -: zoom";
	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, 20, 0x03fc35, menu);
	menu = "8, 2: z-scale; 4, 6:rotation";
	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, 35, 0x03fc35, menu);
	menu = "f: full screen mode";
	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, 50, 0x03fc35, menu);
}
