
void	ft_keymove(int kc, t_data *data)
{
	if (kc == UP)
		data->t_pos.iy += 40;
	else if (kc == DOWN)
		data->t_pos.iy -= 40;
	else if (kc == LEFT)
		data->t_pos.ix -= 40;
	else if (kc == RIGHT)
		data->t_pos.iy += 40;
}

void	ft_keycolor(int kc, t_data *data)
{
	if (kc == R)
		data->color.r -= 20;
	else if (kc == G)
		data->color.g -= 20;
	else if (kc == B)
		data->color.b -= 20;
	else if (kc == A)
	{
		if (data->color.a == data->color.sa)
			data->color.a /= 2;
		else
			data->color.a = data->color.sa;
	}
}

void 	ft_switchproj(t_data *data)

	if (data->proj == PROJ_MAX)
		data->proj = 0;
	else
		data->proj++;
}

void	ft_keyzoom(int kc, t_data *data)
{
	if (kc == MORE)
	{
		data->space -= 5;
		if (data->space == 0)
			data->space = 1;
	}
	else if (kc == LESS)
	{
		data->space += 5;
	}
}

void	ft_keypad(int kc, t_data *data)
{
	if (kc == MULT)
	{
		data->pos.rx += 1;
		data->pos.ry += 5;
	}
	else if (kc == DIV)
	{
		data->pos.rx -= 1;
		data->pos.ry -= 5;
	}
}
