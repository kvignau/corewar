/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:41:25 by mchevall          #+#    #+#             */
/*   Updated: 2016/09/29 16:41:27 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
#define ASM_H
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
int					file_manager(t_data *data);
#endif
