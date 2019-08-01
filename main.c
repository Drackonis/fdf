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
	t_data	data;

	begin = read_arg(argc, argv, begin, &data);
	data.begin = &begin;
	data.tab = ft_settab(&begin, &data);



	printf("DATA NB LINES--->%d\n", data.nblin);
	////DEBUG_____________________________
	
	int i = 0;
	int j = 0;
	while(data.tab[i])
	{
		printf("%d|", i % 10);
		j = 0;
		while(j < data.nbcol/*data.tab[i][j]*/)
		{
			if (data.tab[i][j] >= 0 && data.tab[i][j] < 10)
				printf(" ");
			printf("%d ", data.tab[i][j]);	
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
