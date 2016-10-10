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


/*
**********************  Typedef  **********************
*/



/*
**********************  Structures  **********************
*/

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

typedef struct 		s_lab
{
	char			*name;
	int				oct;
}					t_lab;
/*
**********************  Cleaning  **********************
*/

int					store_file(char **argv, t_data *data, int *i);
int					file_manager(t_data *data, int nb_lines);
int					ft_iscomment(int c);
int					header_manager(t_data *data);
int					name_manager(t_data *data, int *i, int *j);
int					comment_manager(t_data *data, int *i, int *j);
void				error(t_data *data, char *str);


/*
**********************  Recovery  **********************
*/

void				recovery(t_data *data);
int					check_line(char	*line, t_data **data); //maybe static
int					line_valid(char *line, t_data **data); //maybe static
int					check_first(char *line, t_data **data); //maybe static
int					label_valid(char *name); //maybe static
int					check_label(char *name, t_data **data);
int					check_instruct(char *line, char *name, t_data **data);
void				ft_strtrim_tab(char **args_tab);
int					check_args(char **args_tab, int op_code, t_data **data); //maybe static


/*
**********************  Display  **********************
*/

void				display_file(t_data *data);
void				show_label_lst(t_dbllist *lst);

/*
**********************  Initializer  **********************
*/

void				data_initializer(t_data **data);
void				ini_lab(t_lab *lab, t_data **data);

/*
**********************  No leaks  **********************
*/

void				free_all_data(t_data *data);
void				free_tab_char(char ***tab);

#endif
