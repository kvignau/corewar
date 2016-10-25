/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champions_maker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 19:06:51 by mchevall          #+#    #+#             */
/*   Updated: 2016/10/11 19:07:08 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		reverse_byte(int buf, int readv)
{
	if (readv == (sizeof(int)))
		return (((buf >> 24) & 0xff) |
				((buf << 8) & 0xff0000) |
				((buf >> 8) & 0xff00) |
				((buf << 24) & 0xff000000));
	else if (readv == 3)
		return (((buf << 16) & 0xff0000)) |
				((buf << 0) & 0xff00) |
				((buf >> 16) & (0xff));
	else if (readv == 2)
		return (((buf << 8) & 0xff00) | (buf >> 8));
	else
		return(buf);
}

int		filetotab(int **stock, int *file_size, t_var *var)
{
	int	fd;
	int	buf;
	int	readv;

	if ((fd = open(var->argv[var->i], O_RDONLY)) == -1)
		return (0);
	while ((readv = read(fd, &buf, sizeof(int))) != 0)
	{
		if (readv == -1)
			return (-1);
		else if ((*file_size + readv * 2) > COR_MAX_VALUE)
			return (-2);
		else
		{
			buf = reverse_byte(buf, readv);
			ft_memcpy(&(*stock)[*file_size / sizeof(int)], &buf, sizeof(int));
			buf = 0;
			*file_size += readv * 2;
		}
	}
	return (((*file_size) <= COR_MIN_VALUE) ? -3 : 1);
}

void	invalid_file(int error, t_var *var)
{
	if (error == 1)
	{
		ft_putstr_fd("File ", 2);
		ft_putstr_fd(var->argv[var->i], 2);
		ft_putstr_fd(" must be at most ",2);
		ft_putnbr_fd(COR_MAX_VALUE, 2);
		ft_putstr_fd(" bytes to be a valid champion\n", 2);
	}
	else if (error == 2)
	{
		ft_putstr_fd("File ", 2);
		ft_putstr_fd(var->argv[var->i], 2);
		ft_putstr_fd("must be at least ", 2);
		ft_putnbr_fd(COR_MIN_VALUE + 1, 2);
		ft_putstr_fd(" bytes to be a valid champion\n", 2);
	}
	else if (error == 3)
	{
		ft_putstr_fd("File ", 2);
		ft_putstr_fd(var->argv[var->i], 2);
		ft_putstr_fd(" has an invalid header\n", 2);
	}
}

void	error_manager(int ret, t_var *var)
{
	ft_putstr_fd("Error: ", 2);
	if (ret == 0)
		ft_putstr_fd("Open error\n", 2);
	else if (ret == -1)
		ft_putstr_fd("Read error\n", 2);
	else if (ret == -2)
		invalid_file(1, var);
	else if (ret == -3)
		invalid_file(2, var);
	else if (ret == -4)
		invalid_file(3, var);
}

char		*get_content(int *str, int size)
{
	char	*content;
	int		i;
	int		j;

	content = (char *)ft_memalloc(1);
	i = 0;
	ft_printf("hex: %.x\n", str[i]);
	ft_printf("\n\n|str| : [%s]\n", ft_itoabase_imax(str[i], 16));
	while (i < size / 2)
	{
		content = ft_strjoinandfree(content, ft_itoabase_imax(str[i], 16), 3);
		i += 2;
	}
	return (content);
}

int		champion_validity_checker(t_var *var, t_champ *champ)
{
	ft_printf("champion_validity_checker\n");
	int					file_size;
	int					*stock;
	int					ret;
	int i = 0;

	file_size = 0;
	stock = (int *)ft_memalloc(COR_MAX_VALUE / 2);
	if ((ret = filetotab(&stock, &file_size, var)) != 1)
	{
		error_manager(ret, var);
		return (0);
	}
	ft_printf("ret: %d\n", ret);
	if (COREWAR_EXEC_MAGIC != stock[0])
	{
		error_manager(-4, var);
		return(0);
	}
	int j = 0;
	i = EXEC_MAGIC_LENGTH + PROG_NAME_LENGTH / 2 + 2;
	/*while (j <= (COMMENT_LENGTH / 2))
	{
		ft_printf("[%d] : %.8x\n", i, stock[i + j]);
		j += 2;
	}*/
	champ->name = ft_hextoa(&stock[EXEC_MAGIC_LENGTH / 2], PROG_NAME_LENGTH);
	if ((champ->size = stock[PROG_NAME_LENGTH / 2 + EXEC_MAGIC_LENGTH]) != (file_size - COR_MIN_VALUE - 1))
	{
		ft_putstr("sdfgsdfgsdgsdfg");
	}
	champ->comment = ft_hextoa(&stock[(EXEC_MAGIC_LENGTH + PROG_NAME_LENGTH / 2) + PAD], COMMENT_LENGTH);
	champ->content = get_content(&stock[(COR_MIN_VALUE / 4)], champ->size);

	//ft_printf("Hello: %s\n", ft_hextoa(&stock[EXEC_MAGIC_LENGTH / 2], PROG_NAME_LENGTH / 8));
	//ft_printf("BOB :  %.8x\n", stock[PROG_NAME_LENGTH / 2 + EXEC_MAGIC_LENGTH]);
	i = 0;
	/*while (i <= file_size / 4)
	{
		ft_printf("%.x\n",stock[i]);
		i+= 2;
	}*/
	ft_printf("COR_MAX_VALUE : %d\n", COR_MAX_VALUE);
	ft_printf("file_size: %d\n", file_size);
	ft_printf("%d\n", COR_MIN_VALUE);
	ft_printf("%d\n", sizeof(&stock));
	ft_printf("yo : %d\n", champ->size);
	ft_printf("%s\n", champ->name);
	ft_printf("%s\n", champ->comment);
	ft_printf("%.8x\n", stock[COR_MIN_VALUE /4]);
	ft_printf("%d\n", EXEC_MAGIC_LENGTH + (PROG_NAME_LENGTH + COMMENT_LENGTH)/ 2 + PAD);
	ft_printf("\n%s\n", champ->content);
	return (1);
}

int		set_champion(t_var *var, t_options *opt, t_champ *champ)
{
	ft_printf("set_champion\n");
	static int			id = 1;
	static unsigned int	vm_number = -1;

	champ->id = id;
	id++;
	if (opt->bool_vm_number == 1)
	{
		champ->vm_number = &opt->vm_number;
		opt->vm_number = 0;
	}
	else
	{
		champ->vm_number = &vm_number;
		vm_number--;
	}
	if (champion_validity_checker(var, champ) == 0)
		return (0);
	return(1);
}

int		champions_maker(t_dbllist *champ_list, t_options *options, t_var *var)
{
	t_champ				champ;

	bzero(&champ, sizeof(t_champ));
	if (set_champion(var, options, &champ) == 0)
	{
		ft_printf("set_champion return (0)\n");
		//free(&champ);
		return (0);
	}
	ft_lstdbladd_tail(champ_list, &champ, sizeof(t_champ));
	return (1);
}