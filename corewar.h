/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 14:02:51 by mchevall          #+#    #+#             */
/*   Updated: 2016/09/29 14:03:16 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
#define COREWAR_H
# include "libftprintf/includes/ft_printf.h"
# include "op.h"
# include <fcntl.h>
# define BUFF 1024

typedef struct 		s_data
{
	char			**file;
	char			*line;
}					t_data;

int					store_file(char **argv, t_data *data, int i);
void				data_initializer(t_data **data);
#endif
