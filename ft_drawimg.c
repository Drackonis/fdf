/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawimg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 14:22:26 by rkergast          #+#    #+#             */
/*   Updated: 2019/08/20 16:10:32 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_putpix(t_data *data, int x, int y)
{
	if (x > 0 && y > 0 && x < data->winwidth && y < data->winheight)
	{
		data->img.data[(x * (data->img.bpp / 8)) +
			(y * data->img.size_line)] = data->color.r;
		data->img.data[(x * (data->img.bpp / 8)) +
			(y * data->img.size_line) + 1] = data->color.g;
		data->img.data[(x * (data->img.bpp / 8)) +
			(y * data->img.size_line) + 2] = data->color.b;
	}
}

void		ft_drawcolumn(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j <= data->nbcol)
	{
		//printf("i=%d\n", i);
		i = 0;
		while (i < data->nblin)
		{
			//printf("j=%d\n", j);
			data->pt.x1 = ft_tabtoisox(i , j, data) + data->winwidth / 2;
			data->pt.y1 = ft_tabtoisoy(i , j, data) + data->winheight / 2;
			data->pt.x2 = ft_tabtoisox(i + 1, j, data) + data->winwidth / 2;
			data->pt.y2 = ft_tabtoisoy(i + 1, j, data) + data->winheight / 2;
			//printf("X1:%d|Y1:%d|X2:%d|Y2:%d\n", data->pt.x1, data->pt.y1, data->pt.x2, data->pt.y2);
			//data->pt.y1 += data->tab[i][j];
			//data->pt.y2 += data->tab[i + 1][j];
			ft_bresenham(data);
			i++;
		}
		j++;
	}
}

void		ft_drawline(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= data->nblin)
	{
		//printf("i=%d\n", i);
		j = 0;
		while (j < data->nbcol)
		{
			//printf("j=%d\n", j);
			data->pt.x1 = ft_tabtoisox(i , j, data) + data->winwidth / 2;
			data->pt.y1 = ft_tabtoisoy(i , j, data) + data->winheight / 2;
			data->pt.x2 = ft_tabtoisox(i, j + 1, data) + data->winwidth / 2;
			data->pt.y2 = ft_tabtoisoy(i, j + 1, data) + data->winheight / 2;
			//printf("X1:%d|Y1:%d|X2:%d|Y2:%d\n", data->pt.x1, data->pt.y1, data->pt.x2, data->pt.y2);
			//data->pt.y1 += data->tab[i][j];
			//data->pt.y2 += data->tab[i][j + 1];
			ft_bresenham(data);
			j++;
		}
		i++;
	}
}

void		ft_drawimg(t_data *data)
{
	int i;
	int j;
	int lg;

	lg = 10 * data->space;
	i = 0;
	j = 0;
	printf("DATA NB LINES--->%d\n", data->nblin);
	printf("DATA NB COLUM--->%d\n", data->nbcol);
	printf("WINSIZEWIDTH = %d\n", data->winwidth);
	printf("WINSIZEHEIGHT = %d\n", data->winheight);
	printf("SPACE = %d\n\n", data->space);

	while (data->tab[i])
	{
			printf("%d|", i % 10);
			j = 0;
			while (j < data->nbcol)
			{
				if (data->tab[i][j] >= 0 && data->tab[i][j] < 10)
					printf("  ");
				else if (data->tab[i][j] >= -9 && data->tab[i][j] <= 99)
					printf(" ");
				printf("%d|", data->tab[i][j]);
				j++;
			}
		i++;
		printf("\n");
	}

	data->pt.x1 = 500;
	data->pt.y1 = 500;
	data->pt.x2 = 495;//data->winheight;;
	data->pt.y2 = 550;//data->winwidth;
	//printf("X1:%d|Y1:%d|X2:%d|Y2:%d\n", data->pt.x1, data->pt.y1, data->pt.x2, data->pt.y2);
	ft_bresenham(data);


	data->pt.x1 = 500;
	data->pt.y1 = 500;
	data->pt.x2 = 450;//data->winheight;;
	data->pt.y2 = 505;//data->winwidth;
	//printf("X1:%d|Y1:%d|X2:%d|Y2:%d\n", data->pt.x1, data->pt.y1, data->pt.x2, data->pt.y2);
	ft_bresenham(data);


	/*data->pt.x1 = data->winwidth / 2;
	data->pt.y1 = data->winheight / 2;
	data->pt.x2 = data->pt.x1 + lg;//data->winheight;;
	data->pt.y2 = data->pt.y1 + lg;//data->winwidth;
	ft_bresenham(data);
	data->pt.x1 = data->winwidth / 2;
	data->pt.y1 = data->winheight / 2;
	data->pt.x2 = data->pt.x1 - lg;//data->winheight;;
	data->pt.y2 = data->pt.y1 + lg;//data->winwidth;
	ft_bresenham(data);
	data->pt.x1 = data->winwidth / 2;
	data->pt.y1 = data->winheight / 2;
	data->pt.x2 = data->pt.x1 + lg;//data->winheight;;
	data->pt.y2 = data->pt.y1 - lg;//data->winwidth;
	ft_bresenham(data);
	data->pt.x1 = data->winwidth / 2;
	data->pt.y1 = data->winheight / 2;
	data->pt.x2 = data->pt.x1 - lg;//data->winheight;;
	data->pt.y2 = data->pt.y1 - lg;//data->winwidth;
	ft_bresenham(data);*/

	//ft_drawline(data);
	//ft_drawcolumn(data);


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
