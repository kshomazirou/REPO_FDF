/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:24:24 by kshoma            #+#    #+#             */
/*   Updated: 2024/02/24 11:34:46 by kshoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *s)
{
	ft_printf("%s\n", s);
	exit(1);
}

void	get_data_from_map(char *line, t_fdf **data, int y)
{
	char	**map_data;
	int		x;

	map_data = ft_split(line, ' ');
	x = 0;
	while (map_data[x])
	{
		data[y][x].z = ft_atoi(map_data[x]);
		data[y][x].x = x;
		data[y][x].y = y;
		data[y][x].is_last = 0;
		free(map_data[x++]);
	}
	free(map_data);
	free(line);
	data[y][--x].is_last = 1;
}

t_fdf	**map_memory(char *file_name)
{
	t_fdf		**new;
	int			x;
	int			y;
	int			fd;
	char		*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd <= 0)
		ft_error("NOT EXIST FILE!");
	line = get_next_line(fd);
	x = deli_count(line, ' ');
	free(line);
	y = 0;
	line = get_next_line(fd);
	while (line > 0)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	new = (t_fdf **)malloc(sizeof(t_fdf *) * (++y + 1));
	while (y > 0)
		new[--y] = (t_fdf *)malloc(sizeof(t_fdf) * (x + 1));
	return (close(fd), new);
}

t_fdf	**read_file(char *file_name)
{
	int			fd;
	int			y;
	char		*line;
	t_fdf		**data;

	data = map_memory(file_name);
	fd = open(file_name, O_RDONLY, 0);
	y = 0;
	line = get_next_line(fd);
	while ((line) > 0)
	{
		get_data_from_map(line, data, y++);
		line = get_next_line(fd);
	}
	free(line);
	data[y] = NULL;
	close(fd);
	return (data);
}
