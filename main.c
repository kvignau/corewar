#include "corewar.h"
#include <stdio.h>
#include <fcntl.h>
int		main(int argc, char **argv)
{
	int		fd;
	char	*buffer;
	char	*stock;

	printf("hello, %d\n", argc);
	if (argc != 1)
	{
		fd = clean_open(argv[1], O_RDONLY);
		while (read(fd, buffer, 1024) != 0)
		{
			stock = ft_strjoin(stock, buffer);
		}
		printf("%s", stock);
	}
	else
		ft_putstr("Please provide at least one .s file");
	return (0);
}