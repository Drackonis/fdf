/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabtopix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:44:33 by rkergast          #+#    #+#             */
/*   Updated: 2019/08/14 13:18:53 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		tabtoisoy(int x, int y)
{
	int py;

	return (py);
}

int		tabtoisox(int x, int y)
{
	int px;

	return (px);
}

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
}
