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
		ft_putstr_fd(" bytes to be a valid champion.\n", 2);
	}
	else if (error == 2)
	{
		ft_putstr_fd("File ", 2);
		ft_putstr_fd(var->argv[var->i], 2);
		ft_putstr_fd("must be at least ", 2);
		ft_putnbr_fd(COR_MIN_VALUE + 1, 2);
		ft_putstr_fd(" bytes to be a valid champion.\n", 2);
	}
	else if (error == 3)
	{
		ft_putstr_fd("File ", 2);
		ft_putstr_fd(var->argv[var->i], 2);
		ft_putstr_fd(" has an invalid header.\n", 2);
	}
	else if (error == 4)
	{
		ft_putstr_fd("File ", 2);
		ft_putstr_fd(var->argv[var->i], 2);
		ft_putstr_fd(" is not the size specified in header.\n", 2);
	}
}

void	error_manager(int ret, t_var *var)
{
	ft_putstr_fd("Error: ", 2);
	if (ret == 0)
		ft_putstr_fd("Open error.\n", 2);
	else if (ret == -1)
		ft_putstr_fd("Read error.\n", 2);
	else if (ret == -2)
		invalid_file(1, var);
	else if (ret == -3)
		invalid_file(2, var);
	else if (ret == -4)
		invalid_file(3, var);
	else if (ret == -5)
		invalid_file(4, var);
}

int		champion_validity_checker(t_var *var, t_champ *champ)
{
	int					file_size;
	int					*stock;
	int					ret;

	file_size = 0;
	stock = (int *)ft_memalloc(COR_MAX_VALUE / 2);
	if ((ret = filetotab(&stock, &file_size, var)) != 1)
	{
		error_manager(ret, var);
		return (0);
	}
	if (COREWAR_EXEC_MAGIC != stock[0])
	{
		error_manager(-4, var);
		return(0);
	}
	champ->name = ft_strdup(ft_hextoa(&stock[EXEC_MAGIC_LENGTH / 2], PROG_NAME_LENGTH));
	if ((champ->size = stock[PROG_NAME_LENGTH / 2 + EXEC_MAGIC_LENGTH]) != (file_size - COR_MIN_VALUE) / 2)
	{
		error_manager(-5, var);
		return (0);
	}
	champ->comment = ft_strdup(ft_hextoa(&stock[(EXEC_MAGIC_LENGTH + PROG_NAME_LENGTH) / 2 + PAD], COMMENT_LENGTH));
	champ->content = get_content(&stock[(COR_MIN_VALUE / 4)], champ->size * 2);
	return (1);
}

int		set_champion(t_var *var, t_options *opt, t_champ *champ)
{
	static int			id = 1;
	static unsigned int	vm_number = -1;

	champ->id = id;
	id++;
	if (opt->bool_vm_number == 1)
	{
		champ->vm_number = opt->vm_number;
		opt->vm_number = 0;
	}
	else
	{
		champ->vm_number = vm_number;
		vm_number--;
	}
	if (champion_validity_checker(var, champ) == 0)
		return (0);
	return(1);
}

int		champions_maker(t_dbllist *champ_list, t_options *options, t_var *var)
{
	t_champ				champ;

	ft_bzero(&champ, sizeof(t_champ));
	if (set_champion(var, options, &champ) == 0)
		return (0);
	ft_lstdbladd_tail(champ_list, &champ, sizeof(t_champ));
	return (1);
}