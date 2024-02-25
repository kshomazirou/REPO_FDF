/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:09:33 by kshoma            #+#    #+#             */
/*   Updated: 2024/02/25 11:25:30 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	mod(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void	color_judge(int *color, t_fdf a, t_fdf b)
{
	if (b.z || a.z)
		*color = 0xfc0345;
	else
		*color = 0xBBFAFF;
	if (b.z != a.z)
		*color = 0xfc031c;
}

float	max_judge(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}



void bresenham(t_fdf a, t_fdf b, t_fdf *data, int *img_data) {
    float x_step;
    float y_step;
    float max;
    int color;

    set_param(&a, &b, data);

    float x_diff = b.x - a.x;
    float y_diff = b.y - a.y;

    x_step = x_diff;
    y_step = y_diff;

    max = max_judge(mod(x_step), mod(y_step));
    x_step /= max;
    y_step /= max;

    color_judge(&color, a, b);

    while ((int)(a.x - b.x) || (int)(a.y - b.y)) {
        int pixel_x = (int)a.x;
        int pixel_y = (int)a.y;

        if (pixel_x >= 0 && pixel_x < data->win_x && pixel_y >= 0 && pixel_y < data->win_y) {
            img_data[pixel_y * data->win_x + pixel_x] = color;
        }

        a.x += x_step;
        a.y += y_step;

        if (a.x > data->win_x || a.y > data->win_y || a.y < 0 || a.x < 0) {
            break;
        }
    }
}

/*
void bresenham(t_fdf a, t_fdf b, t_fdf *data, int *img_data) {
    float x_step;
    float y_step;
    float max;
    int color;

    set_param(&a, &b, data);

    float x_diff = b.x - a.x;
    float y_diff = b.y - a.y;

    x_step = x_diff;
    y_step = y_diff;

    max = max_judge(mod(x_step), mod(y_step));
    x_step /= max;
    y_step /= max;

    color_judge(&color, a, b);

    while ((int)(a.x - b.x) || (int)(a.y - b.y)) {
        int pixel_x = (int)a.x;
        int pixel_y = (int)a.y;

        if (pixel_x >= 0 && pixel_x < data->win_x && pixel_y >= 0 && pixel_y < data->win_y) {
            img_data[pixel_y * data->win_x + pixel_x] = color;
        }

        a.x += x_step;
        a.y += y_step;

        if (a.x > data->win_x || a.y > data->win_y || a.y < 0 || a.x < 0) {
            break;
        }
    }
}
*/



void	draw(t_fdf **data)
{
	int		x;
	int		y;
	void	*img_ptr;
	int bpp = 32;
	int size_line = data[0][0].win_x * (bpp / 8);
	int endian = 0;

	img_ptr = mlx_new_image(data[0][0].mlx_ptr, data[0][0].win_x, data[0][0].win_y);
	int *img_data = (int *)mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	y = 0;
	while (data[y])
	{
		x = 0;
		while (1)
		{
			if (data[y + 1])
				bresenham(data[y][x], data[y + 1][x], &data[0][0], img_data);
			if (!data[y][x].is_last)
				bresenham(data[y][x], data[y][x + 1], &data[0][0], img_data);
			if (data[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data[0][0].mlx_ptr, data[0][0].win_ptr, img_ptr, 0, 0);
	print_data(data[0][0]);
}
