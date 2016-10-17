#include "asm.h"

int		ft_islabelchar(int c)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(LABEL_CHARS);
	while (c != LABEL_CHARS[i] && i <= j)
		i++;
	if (i < j)
		return (1);
	else
		return (0);
}