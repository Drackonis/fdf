/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:58:25 by rkergast          #+#    #+#             */
/*   Updated: 2019/09/02 16:00:21 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int				main(int argc, char **argv)
{
	t_lines		begin;
	t_data		data;

	argc--;
	begin.index = 0;
	begin = read_arg(argv, begin, &data);
	data.begin = &begin;
	data.tab = ft_settab(&begin, &data);
	ft_initmlx(&data);
	return (0);
}
