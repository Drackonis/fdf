/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:05:18 by rkergast          #+#    #+#             */
/*   Updated: 2018/12/17 19:20:53 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

char	*ft_strnclr(char *s, int i)
{
	char	*new;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	new = ft_strnew(ft_strlen(s) - i);
	while (s[i])
		new[j++] = s[i++];
	new[j] = '\0';
	ft_strdel(&s);
	return (new);
}

char	*ft_strfreejoin(char *s1, char *s2)
{
	char	*new;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	new = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (new);
}

int		get_next_line(const int fd, char **line)
{
	static char		*tab[256];
	char			*buf;
	int				ret;
	int				i;

	ret = 0;
	i = 0;
	if (fd < 0 || line == NULL || !(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tab[fd] = ft_strfreejoin(tab[fd], buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	ft_strdel(&buf);
	if (ret < BUFF_SIZE && !ft_strlen(tab[fd]))
		return (0);
	while (tab[fd][i] != '\n' && tab[fd][i] != '\0')
		i++;
	if (i == (int)ft_strlen(tab[fd]))
	{
		*line = ft_strdup(tab[fd]);
		ft_strclr(tab[fd]);
	}
	else
	{
		*line = ft_strsub(tab[fd], 0, i);
		tab[fd] = ft_strnclr(tab[fd], i + 1);
	}
	return (1);
}

t_lines		*set_link(int idx, char *line)
{
	t_lines *new;

	if (!(new = (t_lines*)malloc(sizeof(t_lines))))
		return(NULL);
	new->index = idx;
	new->line = ft_strdup(line);
	return (new);
}

t_lines		set_chain(int fd, t_lines begin)
{
	char		*line;
	int 		ret;
	int		idx;
	int		start;
	t_lines		*current;

	ret = 0;
	idx = 0;
	start = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (start == 0)
		{
			begin.index = idx;
			begin.line = ft_strdup(line);
			current = &begin;
		}
		else
		{
			current->next = set_link(idx, line);
			current = current->next;
		}
		idx++;
		start++;
		free(line);
		line = NULL;
	}
	current->next = NULL;
	return (begin);
}

t_lines		read_arg(int argc, char **argv, t_lines begin)
{
	int		fd;
	char		*line;
	int		ret;

	ret = 0;
	if (argv[1])
		fd = open(argv[1], O_RDONLY);
	begin = set_chain(fd, begin);
	if (argv[1])
		close(fd);
	return (begin);
}


