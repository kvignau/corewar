/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trad_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	trad_reg(char *arg, t_hexa *hex)
{
	ft_printf("TRAD REG\n");
	int		i;
	char	*tmp;

	i = 1;
	tmp = ft_itoabase_imax(ft_atoi(ft_strsub(arg, 1, ft_strlen(&arg[i]))), 16);
	if (ft_strlen(tmp) != 2)
		ft_putstr("a completer de 0");
	else
		ft_putstr("good");
	// hex->hexa = ft_strcat(ft_strdup("0"), ft_strsub(arg, 1, ft_strlen(&arg[i])));
	// ft_printf("hex->hexa : %s\n", hex->hexa);
	// ft_printf("n : %d\n", n);
}

void	trad_dir(char *arg, t_hexa *hex)
{
	ft_printf("TRAD DIRs\n");
}

void	trad_ind(char *arg, t_hexa *hex)
{
	ft_printf("TRAD IND\n");
}

