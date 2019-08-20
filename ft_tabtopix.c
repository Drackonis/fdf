/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabtopix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:44:33 by rkergast          #+#    #+#             */
/*   Updated: 2019/08/20 15:18:12 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		ft_tabtoisoy(int x, int y, t_data *data)
{
	int py;

	py = (x * data->space) - (y * data->space);
	//printf("ytAB:%d|PY:%d\n", data->tab[x][y], py);
	/*if (data->tab[x][y] != 0)
		py += data->tab[x][y];*/
	//printf("PY:%d\n", py);
	return (py);
}

int		ft_tabtoisox(int x, int y, t_data *data)
{
	int px;

	px = (y * data->space) + (x * data->space);
	//printf("xTAB:%d|PX:%d\n", data->tab[x][y], px);
	/*if (data->tab[x][y] != 0)
		px += data->tab[x][y];*/
	//printf("PY:%d\n", px);
	return (px);
}
/*
int		ft_tabtopix(t_data *data)
{
	int x;
	int y;
	int i;
	int j;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	while (data->tab[i])
	{
		j = 0;
		while (data->tab[i][j])
		{
			j++;
		}
		i++;
	}
}*/
