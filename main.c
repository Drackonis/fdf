/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:58:25 by rkergast          #+#    #+#             */
/*   Updated: 2019/08/14 15:13:31 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int				main(int argc,char **argv)
{
	t_lines		begin;
	t_data		data;

	argc--;
	//data.mlx_ptr = mlx_init();
	begin = read_arg(argv, begin, &data);
	data.begin = &begin;
	data.tab = ft_settab(&begin, &data);
	ft_initmlx(&data);
	//ft_setwin(&data);


	////DEBUG_____________________________
	
	int			i = 0;
	int			j = 0;
	printf("DATA NB LINES--->%d\n", data.nblin);
	printf("DATA NB COLUM--->%d\n", data.nbcol);
	printf("WINSIZEWIDTH = %d\n", data.winwidth);
	printf("WINSIZEHEIGHT = %d\n", data.winheight);
	printf("SPACE = %d\n\n", data.space);

	while (data.tab[i])
	{
		printf("%d|", i % 10);
		j = 0;
		while (j < data.nbcol)
		{
			if (data.tab[i][j] >= 0 && data.tab[i][j] < 10)
				printf("  ");
			else if (data.tab[i][j] >= -9 && data.tab[i][j] <= 99)
				printf(" ");
			printf("%d|", data.tab[i][j]);	
			j++;
		}
		i++;
		printf("\n");
	}
	
	
	/*
	t_lines *current; 
	current = data.begin;
	while (current->next)
	{
		printf("%d|", current->index % 10);
		printf("%s\n", current->line);
		current = current->next;
	}
	printf("%d|", current->index % 10);
	printf("%s\n", current->line);
	*/
	//____________________________________
	return (0);
}
