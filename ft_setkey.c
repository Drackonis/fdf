/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setkey.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:08:06 by rkergast          #+#    #+#             */
/*   Updated: 2019/08/14 13:15:48 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_keymove(int kc, t_data *data)
{
	if (kc == UP)
		data->pos.iy += 40;
	else if (kc == DOWN)
		data->pos.iy -= 40;
	else if (kc == LEFT)
		data->pos.ix -= 40;
	else if (kc == RIGHT)
		data->pos.iy += 40;
}

void	ft_keycolor(int kc, t_data *data)
{
	if (kc == R)
		data->color.r -= 20;
	else if (kc == G)
		data->color.g -= 20;
	else if (kc == B)
		data->color.b -= 20;
	else if (kc == A)
	{
		if (data->color.a == data->color.sa)
			data->color.a /= 2;
		else
			data->color.a = data->color.sa;
	}
}

void	ft_switchproj(t_data *data)
{
	if (data->proj == PROJ_MAX)
		data->proj = 0;
	else
		data->proj++;
}

void	ft_keyzoom(int kc, t_data *data)
{
	if (kc == MORE)
	{
		data->space -= 5;
		if (data->space == 0)
			data->space = 1;
	}
	else if (kc == LESS)
	{
		data->space += 5;
	}
}

void	ft_keypad(int kc, t_data *data)
{
	if (kc == MULT)
	{
		data->pos.rx += 1;
		data->pos.ry += 5;
	}
	else if (kc == DIV)
	{
		data->pos.rx -= 1;
		data->pos.ry -= 5;
	}
}
