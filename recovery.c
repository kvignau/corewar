/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mchevall          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_first(char *line)
{
	int		i;
	char	*name;

	i = 0;
	while (line[i] != ' ' && line[i] != '\t')
		i++;
	name = ft_strsub(line, 0, i);
	ft_printf("Op: %s",name); //debug
	if (name[ft_strlen(name) - 1] == ':')
		ft_putstr("it's a label\n");
	else
		ft_putstr("instructions\n");
	return (1);
}

int		line_valid(char *line)
{
	check_first(line);
	return (1);
}

int		check_line(char	*line)
{
	if (!(line_valid(line)))
		return (0);
	// ft_putstr("\nVALID\n");
	return (1);
}

void	recovery(t_data *data)
{
	int		i;
	int 	j;

	i = 0;
	j = 0;
	while (i < data->nb_lines)
	{
		if (data->file[i][j] != '\0')
		{
			ft_putstr("Line analysed :\n"); //debug
			ft_printf("%s\n",data->file[i]); //debug
			check_line(data->file[i]);
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
}

	// ft_printf("%s\n", op_tab[0].name);
