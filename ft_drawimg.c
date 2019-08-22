/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawimg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 14:22:26 by rkergast          #+#    #+#             */
/*   Updated: 2019/08/22 17:28:21 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_putpix(t_data *data, int x, int y)
{
	if (x > 0 && y > 0 && x < data->winwidth && y < data->winheight)
	{
		data->img.data[(x * (data->img.bpp / 8)) +
			(y * data->img.size_line) + 2] = data->color.r;
		data->img.data[(x * (data->img.bpp / 8)) +
			(y * data->img.size_line) + 1] = data->color.g;
		data->img.data[(x * (data->img.bpp / 8)) +
			(y * data->img.size_line)] = data->color.b;
	}
}

void		ft_setcolorc(t_data *data, int i, int j)
{
		ft_setgreen(data);
	if (data->tab[i][j] != data->tab[i + 1][j])
	{
		if (data->tab[i][j] >= data->tab[0][0] && data->tab[i + 1][j] >= data->tab[0][0])
			ft_setbrown(data);
		else if (data->tab[i][j] <= data->tab[0][0] && data->tab[i + 1][j] <= data->tab[0][0])
			ft_setcyan(data);
		else
			ft_setyellow(data);
	}
	else if (data->tab[i][j] > data->tab[0][0] || data->tab[i + 1][j] > data->tab[0][0])
		ft_setwhite(data);
	else if (data->tab[i][j] < data->tab[0][0] || data->tab[i + 1][j] < data->tab[0][0])
		ft_setblue(data);
//data->color.r -= data->tab[i + 1][j] * pad + data->tab[i][j] * pad;
	//data->color.g -= data->tab[i + 1][j] * pad + data->tab[i][j] * pad;
	//data->color.b -= data->tab[i + 1][j] * pad + data->tab[i][j] * pad;
}

void		ft_setcolorl(t_data *data, int i, int j)
{
	ft_setgreen(data);
	if (data->tab[i][j] != data->tab[i][j + 1])
	{
		if (data->tab[i][j] >= data->tab[0][0] && data->tab[i][j + 1] >= data->tab[0][0])
			ft_setbrown(data);
		else if (data->tab[i][j] <= data->tab[0][0] && data->tab[i][j + 1] <= data->tab[0][0])
			ft_setcyan(data);
		else
			ft_setyellow(data);
	}
	else if (data->tab[i][j] > data->tab[0][0] || data->tab[i][j + 1] > data->tab[0][0])
		ft_setwhite(data);
	else if (data->tab[i][j] < data->tab[0][0] || data->tab[i][j + 1] < data->tab[0][0])
		ft_setblue(data);
//data->color.r -= data->tab[i][j + 1] * pad + data->tab[i][j] * pad;
	//data->color.g -= data->tab[i][j + 1] * pad + data->tab[i][j] * pad;
	//data->color.b -= data->tab[i][j + 1] * pad + data->tab[i][j] * pad;
}

void		ft_drawcolumn(t_data *data)
{
	int i;
	int j;

	j = 0;
	while (j < data->nbcol)
	{
		i = 0;
		while (i < data->nblin - 1)
		{
			data->pt.x1 = ft_tabtoisox(i , j, data) + data->winwidth / 2;
			data->pt.y1 = ft_tabtoisoy(i , j, data) + data->winheight / 2;
			data->pt.x2 = ft_tabtoisox(i + 1, j, data) + data->winwidth / 2;
			data->pt.y2 = ft_tabtoisoy(i + 1, j, data) + data->winheight / 2;
			//printf("Ctab1:%d|tab2:%d|I:%d|J:%d\n", data->tab[i][j], data->tab[i + 1][j], i , j);
			data->pt.y1 -= data->tab[i][j];
			data->pt.y2 -= data->tab[i + 1][j];
			ft_setcolorc(data, i, j);
			ft_swap(data);
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
	while (i < data->nblin)
	{
		j = 0;
		while (j < data->nbcol - 1)
		{
			data->pt.x1 = ft_tabtoisox(i , j, data) + data->winwidth / 2;
			data->pt.y1 = ft_tabtoisoy(i , j, data) + data->winheight / 2;
			data->pt.x2 = ft_tabtoisox(i, j + 1, data) + data->winwidth / 2;
			data->pt.y2 = ft_tabtoisoy(i, j + 1, data) + data->winheight / 2;
			//printf("Ctab1:%d|tab2:%d|I:%d|J:%d\n", data->tab[i][j], data->tab[i][j + 1], i , j);
			data->pt.y1 -= data->tab[i][j];
			data->pt.y2 -= data->tab[i][j + 1];
			ft_setcolorl(data, i, j);
			ft_swap(data);
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

	ft_drawline(data);
	ft_drawcolumn(data);

	/*
	   data->pt.x1 = data->winwidth / 2;
	   data->pt.y1 = data->winheight / 2;
	   data->pt.x2 = data->pt.x1 + lg;//data->winheight;;
	   data->pt.y2 = data->pt.y1 + lg;//data->winwidth;
	   ft_swap(data);
	   ft_bresenham(data);
	   data->pt.x1 = data->winwidth / 2;
	   data->pt.y1 = data->winheight / 2;
	   data->pt.x2 = data->pt.x1 - lg;//data->winheight;;
	   data->pt.y2 = data->pt.y1 + lg;//data->winwidth;
	   ft_swap(data);
	   ft_bresenham(data);
	   data->pt.x1 = data->winwidth / 2;
	   data->pt.y1 = data->winheight / 2;
	   data->pt.x2 = data->pt.x1 + lg;//data->winheight;;
	   data->pt.y2 = data->pt.y1 - lg;//data->winwidth;
	   ft_swap(data);
	   ft_bresenham(data);
	   data->pt.x1 = data->winwidth / 2;
	   data->pt.y1 = data->winheight / 2;
	   data->pt.x2 = data->pt.x1 - lg;//data->winheight;;
	   data->pt.y2 = data->pt.y1 - lg;//data->winwidth;
	   ft_swap(data);
	   ft_bresenham(data);*/

}
