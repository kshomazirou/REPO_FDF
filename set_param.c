/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:46:20 by kshoma            #+#    #+#             */
/*   Updated: 2024/02/24 11:24:20 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_fdf *data, double angle)
{
	data->x = (data->x - data->y) * cos(angle);
	data->y = (data->x + data->y) * sin(angle) - data->z;
}

void	zoom(t_fdf *a, t_fdf *b, t_fdf *data)
{
	a->x *= data->scale;
	a->y *= data->scale;
	b->x *= data->scale;
	b->y *= data->scale;
	a->z *= data->z_scale;
	b->z *= data->z_scale;
}

void	set_param(t_fdf *a, t_fdf *b, t_fdf *data)
{
	zoom(a, b, data);
	if (data->is_isometric)
	{
		isometric(a, data->angle);
		isometric(b, data->angle);
	}
	a->x += data->shift_x;
	a->y += data->shift_y;
	b->x += data->shift_x;
	b->y += data->shift_y;
}
