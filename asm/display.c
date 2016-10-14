/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
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

void	show_tab_char(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
}

void	show_lst_recup(t_dbllist *lst)
{
	t_elem	*tmp;

	tmp = lst->tail;
	ft_printf("Data saved :\n");
	while (tmp != NULL)
	{
		if (((t_recup *)((tmp)->content))->label == 1)
			ft_printf("Label named : %s\n", ((t_recup *)((tmp)->content))->label_name);
		else
		{
			ft_printf("Instructions : %s\n", op_tab[(((t_recup *)((tmp)->content))->op_code) - 1].name);
			ft_printf("Opcode : %d\n", ((t_recup *)((tmp)->content))->op_code);
			show_tab_char(((t_recup *)((tmp)->content))->args_tab);
			ft_printf("Sum hexa : %s\n", ((t_recup *)((tmp)->content))->sum);
		}
		tmp = tmp->prev;
		ft_printf("\n");
	}
	ft_printf("\n");
}

// void	show_trad(t_dbllist *lst)
// {
// 	t_elem	*tmp;

// 	tmp = lst->tail;
// 	ft_printf("TRAD :\n");
// 	while (tmp != NULL)
// 	{
// 		if (((t_trad *)((tmp)->content))->label == 1)
// 			ft_printf("Label named : %s\n", ((t_trad *)((tmp)->content))->label_name);
// 		else
// 		{
// 			ft_printf("Hex : %s\n", ((t_trad *)((tmp)->content))->hexa);
// 		}
// 		tmp = tmp->prev;
// 		ft_printf("\n");
// 	}
// 	ft_printf("\n");
// }
