/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:02:26 by rkergast          #+#    #+#             */
/*   Updated: 2019/08/14 13:27:53 by rkergast         ###   ########.fr       */
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
# define PROJ_MAX 1

# define UP 38 //621
# define DOWN 40 //521
# define RIGHT 39 //421
# define LEFT 37 //321
# define ARROW 38 || 40 || 39 || 37

# define R 82 //51
# define G 71 //5
# define B 66 //11
# define A 65 // 

# define SPACE 13 //94
# define ENTER 32 //63
# define ESC 53 //35

# define MORE 107 //96
# define LESS 109 //87
# define MULT 106 //76
# define DIV 111 //57

typedef struct			s_pt
{
	int					x;
	int					y;
}						t_pt;

typedef struct			s_pos
{
	int					ix;
	int					iy;
	int					rx;
	int					ry;
}						t_pos;

typedef struct			s_color
{
	int					color;
	int					r;
	int					g;
	int					b;
	int					a;
	int					sa;
}						t_color;

typedef	struct			s_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					winwidth;
	int					winheight;
	int					space;
	int					nblin;
	int					nbcol;
	int					**tab;
	int					proj;
	int					kc;
	struct s_lines		*begin;
	struct s_pt			pt;
	struct s_pos		pos;
	struct s_color		color;
}						t_data;

typedef struct			s_img
{
	void				*img_ptr;
	char				*data;
	int					bpp;
	int					size_line;
	int					endian;
}						t_img;

typedef struct			s_lines
{
	int					index;
	char				*line;
	struct s_lines		*next;
}						t_lines;

t_lines		read_arg(char **argv, t_lines begin, t_data *data);
t_lines		set_chain(int fd, t_lines begin, t_data *data);
t_lines		*set_link(int idx, char *line);
int			get_next_line(const int fd, char **line);

void		ft_init(t_data *data);
void		ft_setwin(t_data *data);
void		ft_setscreeN(t_data *data);
void		ft_setzoom(t_data *data);

int			**ft_settab(t_lines *begin, t_data *data);
int			*fill_line(t_lines *line);
int			count_number(char *line);
int			isnb(char c);

#endif
