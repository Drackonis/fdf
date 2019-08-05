#include "ft_fdf.h"

void	ft_space(t_data *data)
{
	if (data->nbcol <= 20)
		data->space = 25;
	else if (data->nbcol >= 20 && data->nbcol <= 50)
		data->space = 20;
	else if (data->nbcol >= 50 && data->nbcol <= 100)
		data->space = 15;
	else if (data->nbcol >= 100 && data->nbcol <= 200)
		data->space = 5;
	else
		data->space = 1;
}

void	ft_window(t_data *data)
{
	if (data->nbcol <= 10)
		data->winheight = data->nbcol * 100;
	else if (data->nbcol <= 20)
		data->winheight = data->nbcol * 70;
	else if (data->nbcol >= 20 && data->nbcol <= 50)
		data->winheight = data->nbcol * 40;
	else if (data->nbcol >= 50 && data->nbcol <= 100)
		data->winheight = data->nbcol * 20;
	else if (data->nbcol >= 100 && data->nbcol <= 200)
		data->winheight = data->nbcol * 10;
	else
		data->winheight = data->nbcol * 10;
	if (data->nblin <= 20)
		data->winwidth = data->nblin * 100;
	else if (data->nblin >= 20 && data->nblin <= 50)
		data->winwidth = data->nblin * 40;
	else if (data->nblin >= 50 && data->nblin <= 100)
		data->winwidth = data->nblin * 20;
	else if (data->nblin >= 100 && data->nblin <= 200)
		data->winwidth = data->nblin * 10;
	else
		data->winwidth = data->nblin * 10;
}

void	ft_setwin(t_data *data)
{
	ft_window(data);
	ft_space(data);
}