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

int	reverse_byte(int num)
{
	if ((sizeof(num) * 8) == 32) // if 32bit
		return (((num >> 24) & 0xff) | // move byte 3 to byte 0
				((num << 8) & 0xff0000) | // move byte 1 to byte 2
				((num >> 8) & 0xff00) | // move byte 2 to byte 1
				((num << 24) & 0xff000000)); // byte 0 to byte 3
	else
		return (num >> 8) | (num << 8); // 16 bit
}

int	champion_validity_checker(t_var *var)
{
	ft_printf("champion_validity_checker\n");
	int					fd;
	int					readv;
	int					buf;
	int					max_v;
	int					stock[COR_MAX_VALUE];
	//ft_printf("argv[%d]: %s\n", var->i, var->argv[var->i]);
	max_v = 0;
	if ((fd = open(var->argv[var->i], O_RDONLY)) == -1)
		return (0);
	while ((readv = read(fd, &buf, sizeof(int))) != 0)
	{
		if (readv == -1)
			return (0);
		else if (max_v > COR_MAX_VALUE)
		{
			ft_putstr_fd("File must be ",2);
			ft_putnbr_fd(COR_MAX_VALUE, 2);
			ft_putstr_fd("bytes or less to be a valid .cor\n", 2);
			return (0);
		}
		else
		{
			buf = reverse_byte(buf);
			ft_memcpy(&stock[max_v], &buf, sizeof(int));
			ft_printf("%.8x ||  ", stock[0]);
			ft_printf("%.8x\n", stock[max_v]);
			buf = 0;
			max_v += 1;
		}
	}
	ft_printf("max_v %d\n", max_v);
	ft_printf("readv : %d\n", readv);
	int i = 0;
	while (i < max_v)
	{
		ft_printf("%.8x\n", stock[i]);
		i++;
	}
	//ft_printf("champ_byte: %s\n", champ_byte);

	//write(1, champ_byte, 2269);
	ft_printf("\n");
	//ft_printf("%x\n", champ_byte);
	/*while (i < readv/4)
	{
		ft_printf("%x",champ_byte[i]);
		i++;
	}*/
	return (1);
}

int	set_champion(t_var *var, t_options *opt, t_champ *champ)
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
	if (champion_validity_checker(var) == 0)
		return (0);
	return(1);
}

int	champions_maker(t_dbllist *champ_list, t_options *options, t_var *var)
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