/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:48:49 by rkergast          #+#    #+#             */
/*   Updated: 2019/07/29 18:44:03 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>
#include <stdio.h>

void		ft_putchar(char c)
{
n	write(1, &c, 1);
}

void		ft_putnbr(int i)
{
	while (i > 0)
	{
		ft_putchar(i % 10 + '0');
		i /= 10;
	}
}

int		deal_key(int key, void *param)
{
	ft_putnbr(key);
	write (1, "\n", 1);
	return(0);
}

int		main(int ac, char **av)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "MY WINDOW");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return 0;
}
