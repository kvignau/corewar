/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mchevall          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	display_file(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < data->nb_lines)
	{
		if (data->file[i][j] != '\n' || data->file[i][j] != '\0')
		{
			ft_printf("%s", data->file[i]);
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
}

void	show_label_lst(t_dbllist *lst)
{
	t_elem	*tmp;

	tmp = lst->tail;
	ft_printf("Label KW :\n");
	while (tmp != NULL)
	{
		ft_printf("Label : %s\n", ((t_lab *)((tmp)->content))->name);
		tmp = tmp->prev;
	}
	ft_printf("\n");
}
