/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:17:08 by rkergast          #+#    #+#             */
/*   Updated: 2019/08/16 15:52:22 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_quadran3(t_data *data)
{
	while (1)
	{
		ft_putpix(data, data->pos.ix + data->pt.x1, data->pos.iy + data->pt.y1);
		if (data->pt.x1 == data->pt.x2 && data->pt.y1 == data->pt.y2)
			break;
		data->pt.er2 = data->pt.err;
		if (data->pt.er2 > -data->pt.dx)
		{
			data->pt.err -= data->pt.dy;
			data->pt.x1 += data->pt.sx;
		}
		if (data->pt.er2 < data->pt.dy)
		{
			data->pt.err += data->pt.dx;
			data->pt.y1 += data->pt.sy;
		}
	}
}

void		ft_quadran4(t_data *data)
{
	while (1)
	{
		//printf("%d|%d\n", data->pt.x1, data->pt.x2);
		//getchar();
		ft_putpix(data, data->pos.ix + data->pt.x1, data->pos.iy + data->pt.y1);
		if (data->pt.x1 == data->pt.x2 && data->pt.y1 == data->pt.y2)
			break;
		data->pt.er2 = data->pt.err;
		if (data->pt.er2 > -data->pt.dx)
		{
			data->pt.err -= data->pt.dy;
			data->pt.x1 += data->pt.sx;
		}
		if (data->pt.er2 < data->pt.dy)
		{
			data->pt.err += data->pt.dx;
			data->pt.y1 += data->pt.sy;
		}
	}
}

void		ft_bresenham(t_data *data)
{
	printf("%d|%d\n", data->pos.ix, data->pos.iy);
	data->pt.dx = (int)(data->pt.x2 - data->pt.x1);
	data->pt.sx = (data->pt.x1 < data->pt.x2) ? 1 : -1;
	data->pt.dy = (int)(data->pt.y2 - data->pt.y1);
	data->pt.sy = (data->pt.y1 < data->pt.y2) ? 1 : -1;
	data->pt.err = (data->pt.dx > data->pt.dy ? data->pt.dx : -data->pt.dy) / 2;
	if (data->pt.dy < 0 && data->pt.dx < 0)
		printf("Q1\n");
	if (data->pt.dy < 0 && data->pt.dx > 0)
		printf("Q2\n");
	if (data->pt.dy > 0 && data->pt.dx < 0)
		ft_quadran3(data);
	if (data->pt.dy > 0 && data->pt.dx > 0)
		ft_quadran4(data);
}
