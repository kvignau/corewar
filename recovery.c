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

int		line_valid(char *line)
{
	int		i;

	i = 0;
	return (1);
}

int		check_line(char	*line)
{
	if (!(line_valid(line)))
		return (0);
	ft_putstr("VALID\n");
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
			ft_putstr("Line analysed :"); //debug
			ft_printf("%s",data->file[i]); //debug
			check_line(data->file[i]);
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
}
