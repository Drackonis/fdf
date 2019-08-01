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
	t_lines	begin;

	begin = read_arg(argc, argv, begin);
	////DEBUG_____________________________
	t_lines *current; 
	current = &begin;
	while (current->next)
	{
		printf("%d|", current->index);
		printf("%s\n", current->line);
		current = current->next;
	}
	//____________________________________
	return (0);
}
