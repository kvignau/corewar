/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:41:25 by mchevall          #+#    #+#             */
/*   Updated: 2016/10/04 16:25:01 by mchevall         ###   ########.fr       */
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
	char			**tmpfile;
	char			**cleanfile;
	char			**file;
	char			*line;
	char			*comment;
	char			*name;
}					t_data;

int					store_file(char **argv, t_data *data, int i);
void				data_initializer(t_data **data);
int					file_manager(t_data *data, int nb_lines);
int					ft_iscomment(int c);

/*
**********************  Recovery  **********************
*/

void				recovery(t_data *data);
int					check_line(char	*line);
int					line_valid(char *line);



/*
**********************  Display  **********************
*/

void				display_file(t_data *data);

#endif
