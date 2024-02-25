/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:39:04 by kshoma            #+#    #+#             */
/*   Updated: 2024/02/24 11:33:36 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_key(int key)
{
	return (key == 24 || key == 69 || key == 27 || key == 78 \
	|| key == 91 || key == 28 || key == 84 || key == 19 || \
	key == 126 || key == 125 || key == 123 || key == 124 || \
	key == 49 || key == 87 || key == 23 || key == 86 || \
	key == 21 || key == 88 || key == 22);
}

void	do_key2(int key, t_fdf **data)
{
	if (key == 24 || key == 69)
		data[0][0].scale += 3;
	if (key == 27 || key == 78)
		data[0][0].scale -= 3;
	if (key == 91 || key == 28)
		data[0][0].z_scale += 1;
	if (key == 84 || key == 19)
		data[0][0].z_scale -= 1;
	if (key == 126)
		data[0][0].shift_y -= 10;
	if (key == 125)
		data[0][0].shift_y += 10;
	if (key == 123)
		data[0][0].shift_x -= 10;
	if (key == 124)
		data[0][0].shift_x += 10;
}

void	do_key(int key, t_fdf **data)
{
	do_key2(key, data);
	if (key == 49 || key == 87 || key == 23)
	{	
		data[0][0].is_isometric = 1;
		if (data[0][0].is_isometric)
			data[0][0].is_isometric = 0;
	}
	if (key == 86 || key == 21)
		data[0][0].angle += 0.05;
	if (key == 88 || key == 22)
		data[0][0].angle -= 0.05;
}

int	deal_key(int key, t_fdf **data)
{
	if (is_key(key))
	{
		mlx_clear_window(data[0][0].mlx_ptr, data[0][0].win_ptr);
		do_key(key, data);
		print_data(data[0][0]);
		draw(data);
	}
	if (key == 6 || key == 7 || key == 0 || key == 1 || key == 3)
		new_window(key, data);
	if (key == '5')
	{
		mlx_destroy_window(data[0][0].mlx_ptr, data[0][0].win_ptr);
		exit(0);
	}
	return (0);
}
