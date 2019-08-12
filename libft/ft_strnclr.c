#include "libft.h"

char	*ft_strnclr(char *s, int i)
{
	char 	*new;
	int	j;

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
