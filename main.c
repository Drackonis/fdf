/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:58:25 by rkergast          #+#    #+#             */
/*   Updated: 2018/12/17 18:52:51 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		main(int argc,char **argv)
{
	int 	i;
	t_lines	*begin;
	t_lines *current;

	i = 0;
	begin = read_arg(argc, argv, begin);
	current = begin;
	while (current->next)
	{
		printf("%d|%s|\n", begin->index, begin->line);
		current = current->next;
	}
	return (0);
}
