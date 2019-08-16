/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:02:26 by rkergast          #+#    #+#             */
/*   Updated: 2019/08/16 16:03:51 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

#include "mlx.h"

# include <stdio.h> //ABUSIF
# include <fcntl.h> //GET NEXT LINE NEED
# include <wchar.h>
# include <math.h>
# include "libft/libft.h"

# define BUFF_SIZE 1
# define PROJ_MAX 1

# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define ARROW 123 || 124 || 125 || 126

# define R 15
# define G 5
# define B 11
# define A 0

# define SPACE 49
# define ENTER 36
# define ESC 53

# define MORE 69
# define LESS 78
# define MULT 67
# define DIV 75

typedef struct			s_pt
{
	int					x;
	int					y;
	int					x1;
	int					y1;
	int					x2;
	int					y2;
	int					dx;
	int					sx;
	int					dy;
	int					sy;
	int					err;
	int					er2;
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

typedef struct			s_img
{
	void				*img_ptr;
	char				*data;
	int					bpp;
	int					size_line;
	int					endian;
}						t_img;

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
	struct s_img		img;
}						t_data;

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

int			ft_display(t_data *data);
int			ft_getkey(int kc, t_data *data);

void		ft_keypad(int kc, t_data *data);
void		ft_keyzoom(int kc, t_data *data);
void		ft_switchproj(t_data *data);
void		ft_keycolor(int lc, t_data *data);
void		ft_keymove(int kc, t_data *data);

void		ft_initwin(t_data *data);
void		ft_setwin(t_data *data);
void		ft_setscreen(t_data *data);
void		ft_setzoom(t_data *data);

int			ft_initmlx(t_data *data);

void		ft_drawimg(t_data *data);
void		ft_putpix(t_data *data, int x, int y);

void		ft_bresenham(t_data *data);

#endif
