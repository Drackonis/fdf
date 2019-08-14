/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getkey.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:47:40 by rkergast          #+#    #+#             */
/*   Updated: 2019/08/14 13:15:11 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

/*void	ft_display(t_data *data)
{
	
}*/

void	ft_getkey(int kc, t_data *data)
{
	if (kc == UP || kc == DOWN || kc == RIGHT || kc == LEFT)
		ft_keymove(kc, data);
	else if (kc == R || kc == G || kc == B || kc == A)
		ft_keycolor(kc, data);
	else if (kc == SPACE)
		ft_switchproj(data);
	else if (kc == ENTER)
		ft_init(data);
	else if (kc == ESC)
		exit(0);
	else if (kc == LESS || kc == MORE)
		ft_keyzoom(kc, data);
	else if (kc == DIV || kc == MULT)
		ft_keypad(kc, data);
	ft_display(data);
}
