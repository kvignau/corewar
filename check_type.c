/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mchevall          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		recover_valid_type(int op_code, int *type)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = 0;
	while (op_tab[op_code - 1].arg[i])
	{
		// ft_printf("%s\n", args_tab[i]); //debug
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
	ft_printf("valid type : %d\n", (*type));
	return (*type);
}
int		verif_type(int type, int op_code)
{
	int		i;
	int		valid_type;

	i = 0;
	recover_valid_type(op_code, &valid_type);
	if ((type & valid_type) == type)
		ft_printf("les types sont bons\n");
	else
		ft_printf("les types NE sont PAS bons\n");
	return (1);
}
