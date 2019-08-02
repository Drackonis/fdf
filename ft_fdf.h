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
# include <math.h>
# include "libft/libft.h"

# define BUFF_SIZE 1

typedef	struct			s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int		winwidth;
	int		winheight;
	int		space;
	int		nblin;
	int		nbcol;
	int		**tab;
	struct s_lines	*begin;
}				t_data;

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

t_lines		read_arg(int argc, char **argv, t_lines begin, t_data *data);
int		**ft_settab(t_lines *begin, t_data *data);

#endif
