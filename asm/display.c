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

void	show_lst_hexa(t_dbllist *lst)
{
	t_elem	*tmp;

	tmp = lst->tail;
	ft_putstr("LST_HEXA :\n");
	while (tmp != NULL)
	{
		if (((t_hexa *)((tmp)->content))->hexa)
			ft_printf("%s\n",((t_hexa *)((tmp)->content))->hexa);
		else
			ft_printf("XX");
		tmp = tmp->prev;
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
			show_lst_hexa(((t_recup *)((tmp)->content))->lst_hexa);
		}
		tmp = tmp->prev;
		ft_printf("\n");
	}
	ft_printf("\n");
}

static char	*lsthexa_tostr(t_dbllist *lst)
{
	t_elem	*tmp;
	char	*tmp2;
	char 	*new;
	char	*unkwn;

	tmp = lst->tail;
	tmp2 = NULL;
	new = NULL;
	unkwn = ft_strdup("XX");
	ft_putstr("LST_HEXA :\n");
	while (tmp != NULL)
	{
		if (new == NULL)
			tmp2 = ft_strnew(sizeof(char *));
		else
			tmp2 = ft_strdup(new);
		ft_strdel(&new);
		if (((t_hexa *)((tmp)->content))->hexa)
		{
			new = ft_strjoin(tmp2, ((t_hexa *)((tmp)->content))->hexa);
			ft_printf("%s\n",((t_hexa *)((tmp)->content))->hexa); //debug
		}
		else
		{
			new = ft_strjoin(tmp2, unkwn);
			ft_printf("XX"); //debug
		}
		tmp = tmp->prev;
	}
	ft_strdel(&unkwn);
	return (new);
}

void	show_trad(t_dbllist *lst)
{
	t_elem	*tmp;
	char	*trad;
	char	*tmp2;
	char	*new;

	tmp = lst->tail;
	trad = NULL;
	new = NULL;
	ft_printf("TRAD :\n");
	while (tmp != NULL)
	{
		if (trad == NULL)
			tmp2 = ft_strnew(sizeof(char *));
		else
		{
			tmp2 = ft_strdup(trad);
			ft_strdel(&trad);
		}
		new = lsthexa_tostr(((t_recup *)((tmp)->content))->lst_hexa);
		ft_printf("new : %s\n", new);
		trad = ft_strjoin(tmp2, new);
		ft_printf("TRAD : %s\n", trad);
		ft_strdel(&tmp2);
		ft_strdel(&new);
		tmp = tmp->prev;
	}
	ft_printf("TRAD : %s\n", trad);
	ft_printf("\n");
}
