/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trad.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*sum_args(char **args_tab)
{
	int		i;
	int		type;
	int		sum;

	i = 0;
	type = 0;
	while (args_tab[i])
	{
		type = 0;
		if ((type = define_type_args(args_tab[i])) == 0)
			return (0);
		if (i == 0)
			sum = type << 6;
		else if (i == 1)
			sum = sum | (type << 4);
		else if (i == 2)
			sum = sum | (type << 2);
		else
			return (0);
		i++;
	}
	return (ft_itoabase_imax(sum, 16));
}

// char	*sum_args(char **args_tab)
// {
// 	char	*hex;
// 	int		i;
// 	char	*tmp;

// 	return (hex);
// }

// void	trad_instruction(t_data **data)
// {
// 	t_trad	trad;
// 	int		op_code;
// 	char	*tmp;

// 	ft_bzero(&trad, sizeof(t_trad));
// 	op_code = ((t_recup *)((tmp)->content))->op_code;
// 	tmp = NULL;
// 	trad.hexa = ft_strdup(ft_itoabase_uimax(op_code, 16));
// 	ft_lstdbladd_head((*data)->hex, &recup, sizeof(t_recup));
// 	if (op_tab[op_code - 1].octcod == 1)
// 	{
// 		tmp = ft_strdup(sum_args(((t_recup *)((tmp)->content))->args_tab));
// 	}

// }

// int		trad(t_data **data)
// {
// 	t_elem	*tmp;


// 	tmp = lst->tail;
// 	while (tmp != NULL)
// 	{
// 		if (((t_recup *)((tmp)->content))->label == 0)
// 			trad_instruction(data, &trad);
// 		else
// 		{
// 			trad.label = 1;
// 			trad.label_name = ft_strdup(((t_recup *)((tmp)->content))->label);
// 			ft_lstdbladd_head((*data)->trad, &trad, sizeof(t_trad));
// 		}

// 		tmp = tmp->prev;
// 	}

// 	return (1);
// }
