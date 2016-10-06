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
	char			**file;
	char			*line;
	char			*comment;
	char			*name;
	int				nb_lines;
	t_dbllist		*label_kw;
	t_dbllist		*label_unkw;
}					t_data;

int					store_file(char **argv, t_data *data, int i);
void				data_initializer(t_data **data);
int					file_manager(t_data *data, int nb_lines);
int					ft_iscomment(int c);
int					header_manager(t_data *data);
int					name_manager(t_data *data, int *i, int *j);
int					comment_manager(t_data *data, int *i, int *j);

/*
**********************  Recovery  **********************
*/


/*
**********************  Recovery  **********************
*/

void				recovery(t_data *data);
int					check_line(char	*line, t_data **data);
int					line_valid(char *line, t_data **data);
int					check_first(char *line, t_data **data);



/*
**********************  Display  **********************
*/

void				display_file(t_data *data);

#endif
