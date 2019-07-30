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

#include "get_next_line.h"

int		main(int argc,char **argv)
{
	int		fd;
	char			*line;
	int			ret;
	int 			i;

	i = 0;
	ret = 0;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		i++;
		if (i == 10)
			i = 1;
		printf ("%d|%s|\n", i, line);
		//getchar();
		free(line);
		line = NULL;
	}
	free(line);
	if (argc == 2)
		close(fd);
}
