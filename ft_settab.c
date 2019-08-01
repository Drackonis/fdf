
#include "ft_fdf.h"

int	isnb(char c)
{
	if (c == '-' || c == '+' || (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

int	count_number(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(line[i])
	{
		if (line[i] == ' ')
			i++;
		else if (isnb(line[i]))
		{
			count++;
			while(isnb(line[i]) && line[i])
				i++;
		}
	}
	return (count);
}

int	*fill_line(t_lines *line)
{
	int 	i;
	int	j;
	int	*tab;
	char	*current;
	
	i = 0;
	j = 0;
	if(!(tab = (int*)malloc(sizeof(int) * (count_number(line->line) + 1))))
		return(NULL);
	current = line->line;
	while (*current)
	{
		if (*current == ' ')
			current++;
		else if (isnb(*current))
		{
			tab[j] = ft_atoi(current);
			j++;
			while(isnb(*current) && *current)
				current++;
		}
	}
	tab[j] = 0;
	return(tab);
}

int	**ft_settab(t_lines *begin, t_data *data)
{
	int	**tab;
	t_lines	*current;
	int	i;

	i = 0;
	current = begin;
	if(!(tab = (int**)malloc(sizeof(int*) * (data->nblin + 1))))
		return (NULL);
	while(current)
	{
		tab[i] = fill_line(current);
		current = current->next;
		i++;
	}
	data->nbcol = count_number(begin->line);
	tab[i] = NULL;
	return(tab);
}
