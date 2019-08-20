/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:17:08 by rkergast          #+#    #+#             */
/*   Updated: 2019/08/20 16:37:26 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_quadran1(t_data *data)
{
	data->pt.err = (data->pt.dx > data->pt.dy ? data->pt.dx : -data->pt.dy) / 2;
	printf("Q1\n");
	while (1)
	{
		ft_putpix(data, data->pos.ix + data->pt.x1, data->pos.iy + data->pt.y1);
		if (data->pt.x1 == data->pt.x2 && data->pt.y1 == data->pt.y2)
			break;
		data->pt.er2 = data->pt.err;
		if (data->pt.er2 < -data->pt.dx)
		{
			data->pt.err -= data->pt.dy;
			data->pt.x1 += data->pt.sx;
		}
		if (data->pt.er2 > data->pt.dy)
		{
			data->pt.err += data->pt.dx;
			data->pt.y1 += data->pt.sy;
		}
	}
}


void		ft_quadran2(t_data *data)
{
	data->pt.err = (data->pt.dx > data->pt.dy ? data->pt.dx : -data->pt.dy) / 2;
	int i = 1;
	printf("Q2\n");
	while (i < i + 1)
	{
		//printf("E=%d|DX:%d|DY:%d\n", data->pt.er2, data->pt.dx, data->pt.dy);
		//getchar();
		printf("E2:%d********X1:%d|X2:%d|Y1:%d|Y2:%d\n", data->pt.er2, data->pt.x1, data->pt.x2, data->pt.y1, data->pt.y2);
		ft_putpix(data, data->pos.ix + data->pt.x1, data->pos.iy + data->pt.y1);
		if (data->pt.x1 == data->pt.x2 && data->pt.y1 == data->pt.y2)
			break;
		data->pt.er2 = data->pt.err;
		if (data->pt.er2 > -data->pt.dx )
		{
			data->pt.err -= data->pt.dy;
			data->pt.x1 += data->pt.sx;
		}
		if (data->pt.er2 > data->pt.dy)
		{
			data->pt.err += data->pt.dx;
			data->pt.y1 += data->pt.sy;
		}
	}
}

void		ft_quadran3(t_data *data)
{
	data->pt.err = (data->pt.dx < data->pt.dy ? data->pt.dx / 2 : -data->pt.dy);
	printf("Q3\n");
	while (1)
	{
		printf("E2:%d|DX:%d|DY:%d********X1:%d|X2:%d|Y1:%d|Y2:%d\n", data->pt.er2,data->pt.dx, data->pt.dy, data->pt.x1, data->pt.x2, data->pt.y1, data->pt.y2);
		//getchar();
		ft_putpix(data, data->pos.ix + data->pt.x1, data->pos.iy + data->pt.y1);
		if (data->pt.x1 == data->pt.x2 && data->pt.y1 == data->pt.y2)
			break;
		data->pt.er2 = data->pt.err;
		if (data->pt.er2 < data->pt.dx)
		{
			data->pt.err += data->pt.dy;
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
	data->pt.err = (data->pt.dx > data->pt.dy ? data->pt.dx : -data->pt.dy) / 2;
	printf("Q4\n");
	while (1)
	{
		printf("E2:%d|DX:%d|DY:%d********X1:%d|X2:%d|Y1:%d|Y2:%d\n", data->pt.er2,data->pt.dx, data->pt.dy, data->pt.x1, data->pt.x2, data->pt.y1, data->pt.y2);
		getchar();
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

void		ft_qx1(t_data *data)
{
	data->pt.err = (data->pt.dx > data->pt.dy ? data->pt.dx : -data->pt.dy) / 2;
	while (1)
	{
		ft_putpix(data, data->pos.ix + data->pt.x1, data->pos.iy + data->pt.y1);
		if (data->pt.x1 == data->pt.x2 && data->pt.y1 == data->pt.y2)
			break;
		data->pt.er2 = data->pt.err;
		if (data->pt.er2 < -data->pt.dx)
		{
			data->pt.err -= data->pt.dy;
			data->pt.x1 += data->pt.sx;
		}
		if (data->pt.er2 > data->pt.dy)
		{
			data->pt.err += data->pt.dx;
			data->pt.y1 += data->pt.sy;
		}
	}
}

void		ft_qx0(t_data *data)
{
	data->pt.err = (data->pt.dx > data->pt.dy ? data->pt.dx : -data->pt.dy) / 2;
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



void		ft_bresenham(t_data *data)
{
	data->pt.dx = (int)(data->pt.x2 - data->pt.x1);
	data->pt.sx = (data->pt.x1 < data->pt.x2) ? 1 : -1;
	data->pt.dy = (int)(data->pt.y2 - data->pt.y1);
	data->pt.sy = (data->pt.y1 < data->pt.y2) ? 1 : -1;
	printf("********X1:%d|X2:%d|Y1:%d|Y2:%d\n", data->pt.x1, data->pt.x2, data->pt.y1, data->pt.y2);
	//printf("DX:%d|DY:%d\n", data->pt.dx, data->pt.dy);
	if (data->pt.dy < 0 && data->pt.dx < 0)
		ft_quadran1(data);
	else if (data->pt.dy < 0 && data->pt.dx > 0)
		ft_quadran2(data);
	else if (data->pt.dy > 0 && data->pt.dx < 0)
		ft_quadran3(data);
	else if (data->pt.dy > 0 && data->pt.dx > 0)
		ft_quadran4(data);
	else if ((data->pt.dx == 0 && data->pt.dy < 0) || (data->pt.dx < 0 && data->pt.dy == 0))
		ft_qx1(data);
	else if ((data->pt.dx == 0 && data->pt.dy > 0) || (data->pt.dx > 0 && data->pt.dy == 0))
		ft_qx0(data);
	else if (data->pt.dx == 0 && data->pt.dy == 0)
		write(1, "ERROR\n", 6);
}
