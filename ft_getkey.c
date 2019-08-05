
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
	else if (kc == DIC || kc == MULT)
		ft_keypad(kc ,data);
	ft_display(data);
}

void	ft_display(t_data *data)
{
	
}
