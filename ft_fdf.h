/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:02:26 by rkergast          #+#    #+#             */
/*   Updated: 2019/07/29 15:23:31 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include <stdio.h> //ABUSIF
# include <fcntl.h> //GET NEXT LINE NEED
# include <wchar.h>
# include "libft/libft.h"

# define BUFF_SIZE 1

typedef struct			s_lines
{
	int		index;
	char		*line;
	struct s_lines	*next;
}				t_lines;

typedef struct			s_fdf
{
	int	x;
	int	y;
	int	z;
}				t_fdf;

t_lines		*read_arg(int argc, char **argv, t_lines *begin);

#endif
