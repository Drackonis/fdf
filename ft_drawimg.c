/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawimg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 14:22:26 by rkergast          #+#    #+#             */
/*   Updated: 2019/08/16 15:56:27 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_putpix(t_data *data, int x, int y)
{
	/*data->img.data[x * 4 +
		y * 4 + 2] = data->color.r;*/
	data->img.data[(x * (data->img.bpp / 8)) +
		(y * data->img.size_line)] = data->color.r;
	data->img.data[(x * (data->img.bpp / 8)) +
		(y * data->img.size_line) + 1] = data->color.g;
	data->img.data[(x * (data->img.bpp / 8)) +
		(y * data->img.size_line) + 2] = data->color.b;
	/*data->img.data[(x * 4) +
		(y * data->winheight * 4) + 1] = data->color.g;
	data->img.data[(x * (data->img.bpp / 8)) +
		(y * data->winheight * 4) + 2] = data->color.b;*/
}

void		ft_drawimg(t_data *data)
{
	int i = 0;
	int j = 0;

	printf("DATA NB LINES--->%d\n", data->nblin);
	printf("DATA NB COLUM--->%d\n", data->nbcol);
	printf("WINSIZEWIDTH = %d\n", data->winwidth);
	printf("WINSIZEHEIGHT = %d\n", data->winheight);
	printf("SPACE = %d\n\n", data->space);

	data->pt.x1 = -275;
	data->pt.x2 = 824;//data->winheight;;
	data->pt.y1 = -332;
	data->pt.y2 = 993;//data->winwidth;

	ft_bresenham(data);
	/*while (i < data->winheight * data->winwidth)
	{
		i++;
		//while (j < data->winwidth)
		//{
			ft_putpix(data, i, j);
		//	j++;
		//}
	}*/
}
