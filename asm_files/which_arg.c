/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				args_for_sum(char *arg)
{
	int		type;
	int		i;

	type = 0;
	i = 0;
	if (is_reg(arg))
		return (1);
	if (is_dir(arg))
		return (2);
	if (is_ind(arg))
		return (3);
	return (0);
}

int				define_type_args(char *arg)
{
	int		type;
	int		i;

	type = 0;
	i = 0;
	if (is_reg(arg))
		return (T_REG);
	if (is_ind(arg))
		return (T_IND);
	if (is_dir(arg))
		return (T_DIR);
	return (0);
}

int				define_trad_fct(char *arg)
{
	if (is_reg(arg))
		return (0);
	if (is_dir(arg))
		return (1);
	if (is_ind(arg))
		return (2);
	return (-1);
}
