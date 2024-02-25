/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:41:43 by kshoma            #+#    #+#             */
/*   Updated: 2024/02/24 23:33:23 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "src/printf/libft/libft.h"
# include "src/printf/ft_printf.h"
# include "src/get_next_line/get_next_line.h"
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_fdf
{
	float	x;
	float	y;
	float	z;
	int		is_last;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		z_scale;
	int		scale;
	double	angle;
	int		is_isometric;	
	int		win_x;
	int		win_y;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

t_fdf		**read_file(char *file_name);
void		bresenham(t_fdf a, t_fdf b, t_fdf *data, int *img_data);
void		draw(t_fdf **data);
void		print_data(t_fdf data);
int			deal_key(int key, t_fdf **data);
void		set_param(t_fdf *a, t_fdf *b, t_fdf *data);
void		new_window(int key, t_fdf **data);
void		isometric(t_fdf *data, double angle);
void		ft_error(char *s);

#endif
