/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:40:41 by kshoma            #+#    #+#             */
/*   Updated: 2024/02/24 11:22:14 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_win_size(int key, t_fdf **data)
{
	if ((key == 0 && data[0][0].win_y <= 500) || \
	(key == 6 && data[0][0].win_x <= 500))
		return (1);
	if ((key == 1 && data[0][0].win_y > 1000) || \
	(key == 7 && data[0][0].win_x > 2000))
		return (1);
	return (0);
}

void	full_screen(t_fdf **data)
{
	static int	old_x;
	static int	old_y;

	if (data[0][0].win_x != 2560)
	{
		old_x = data[0][0].win_x;
		old_y = data[0][0].win_y;
	}
	if (data[0][0].win_x == 2560)
		data[0][0].win_x = old_x;
	else
		data[0][0].win_x = 2560;
	if (data[0][0].win_y == 1400)
		data[0][0].win_y = old_y;
	else
		data[0][0].win_y = 1400;
}

void	change_window_size(int key, t_fdf **data)
{
	if (check_win_size(key, data))
		return ;
	if (key == 6)
		data[0][0].win_x -= 100;
	if (key == 7)
		data[0][0].win_x += 100;
	if (key == 0)
		data[0][0].win_y -= 100;
	if (key == 1)
		data[0][0].win_y += 100;
	if (key == 3)
		full_screen(data);
}

void	new_window(int key, t_fdf **data)
{
	change_window_size(key, data);
	mlx_destroy_window(data[0][0].mlx_ptr, data[0][0].win_ptr);
	data[0][0].mlx_ptr = mlx_init();
	data[0][0].win_ptr = mlx_new_window(data[0][0].mlx_ptr, \
	data[0][0].win_x, data[0][0].win_y, "FDF");
	data[0][0].shift_x = data[0][0].win_x / 3;
	data[0][0].shift_y = data[0][0].win_y / 3;
	draw(data);
	mlx_key_hook(data[0][0].win_ptr, deal_key, data);
	mlx_loop(data[0][0].mlx_ptr);
}
