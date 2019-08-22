/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:01:36 by rkergast          #+#    #+#             */
/*   Updated: 2019/08/22 13:03:29 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_swap(t_data *data)
{
	int tmp;

	if (data->pt.x1 > data->pt.x2)
	{
		tmp = data->pt.x1;
		data->pt.x1 = data->pt.x2;
		data->pt.x2 = tmp;
		tmp = data->pt.y1;
		data->pt.y1 = data->pt.y2;
		data->pt.y2 = tmp;
	}
}
