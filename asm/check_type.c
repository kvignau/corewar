/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		recover_valid_type(int op_code, int *type)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = 0;
	while (op_tab[op_code - 1].arg[i])
	{
		tmp = 0;
		if (i == 0)
			(*type) = op_tab[op_code - 1].arg[i];
		else if (i == 1)
			(*type) = (*type) | (op_tab[op_code - 1].arg[i] << 4);
		else if (i == 2)
			(*type) = (*type) | (op_tab[op_code - 1].arg[i] << 8);
		else
			return (0);
		i++;
	}
	return (*type);
}

int				verif_type(int type, int op_code)
{
	int		i;
	int		valid_type;

	i = 0;
	recover_valid_type(op_code, &valid_type);
	if ((type & valid_type) != type)
	{
		ft_printf("One or more of arg's type is invalid\n");
		return (0);
	}
	return (1);
}
