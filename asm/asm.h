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
# include "../libftprintf/includes/ft_printf.h"
# include "op.h"
# include <fcntl.h>
# define BUFF 1024

/*
**********************  Typedef  **********************
*/



/*
**********************  Structures  **********************
*/

typedef struct 		s_final_trad
{
	char			*magic;
	char			*name;
	char			*total_oct;
	char			*comment;
	char			*instruct;

}					t_final_trad;

typedef struct 		s_hexa
{
	char			*hexa;
	char			*lbl_name;
}					t_hexa;

typedef struct 		s_recup
{
	int				label;
	char			*label_name;
	int				pos_oct;
	int				op_code;
	char			**args_tab;
	int				nb_arg;
	// char			*sum;
	t_dbllist		*lst_hexa;
	int				nb_oct;
}					t_recup;

typedef struct 		s_called
{
	char			*name;
	int				trad;
}					t_called;

typedef struct 		s_data_line
{
	int				index;
	int				nb_oct;
	char			*label_declared;
	t_dbllist		*label_called;
}					t_data_line;

typedef struct 		s_data
{
	char			**file;
	char			*line;
	char			*comment;
	char			*name;
	int				nb_lines;
	t_dbllist		*label_kw;
	t_dbllist		*lst_recup;
	t_dbllist		*lst_lines;
	char			*tmp_trad;
	char			*trad;
}					t_data;

typedef struct 		s_lab
{
	char			*name;
	int				oct; //useless ?
}					t_lab;

typedef struct		s_var
{
	int 			i;
	int 			j;
	int 			k;
	int 			l;
	int 			toggle;
	char 			**label_cleaned;
}					t_var;

typedef	void		(*t_trad)(char *, char **, t_data **, int);

/*
**********************  Initializer  *******************
*/

void				data_initializer(t_data **data);
void				ini_lab(t_lab *lab, t_data **data);
void				ini_recup(t_recup **recup);

/*
**********************  File Cleaning  *****************
*/

int					store_file(char **argv, t_data *data, int *i);
int					file_manager(t_data *data, int nb_lines);
int					ft_iscomment(int c);
int					ft_islabelchar(int c);
int					header_manager(t_data *data);
int					label_manager(t_data *data);
int					name_manager(t_data *data, int *i, int *j);
int					comment_manager(t_data *data, int *i, int *j);
int					error(t_data *data, char *str);

/*
**********************  Recovery  **********************
*/

int					recovery(t_data *data);
int					check_line(char	*line, t_data **data); //maybe static
int					label_valid(char *name); //maybe static
int					check_label(char *name, t_data **data, t_data_line *line);
int					check_instruct(char *line, char *name, t_data **data, t_data_line *dline);
void				ft_strtrim_tab(char **args_tab);
int					check_args(char **args_tab, int op_code, t_data **data); //maybe static
int					define_type_args(char *arg);
int					verif_type(int type, int op_code);
int					nb_arg(char **args_tab);
int					exist_label(char *name, t_data **data);
int					is_dir(char *arg);

/*
**********************  Transformation  ****************
*/

void				sum_args(t_recup *recup, char **hexa);
void				trad_reg(char *arg, char **hexa, t_data **data, int op_code);
void				trad_ind(char *arg, char **hexa, t_data **data, int op_code);
void				trad_dir(char *arg, char **hexa, t_data **data, int op_code);
void				trad_args(t_recup *recup, char **hexa, t_data **data, int op_code);
void				trad_label(char *arg, char **hexa, t_data **data, int op_code);
int					define_trad_fct(char *arg);
void				trad_name_instruct(int op_code, char **hexa);
void				hex_to_lower(char **hex);
void				add_zero(char **str, int width);
void				trad_to_str(t_data **data);
char				*lsthexa_tostr(t_dbllist *lst);
void				label_called(t_data_line *dline, char **args_tab);
void				trad_dir_without_label(char *arg, char **hexa, t_data **data, int op_code);
int					index_label_called(char *name, t_dbllist *lst_lines);
int					index_label_declared(char *name, t_dbllist *lst_lines);
// int					find_in_tb_char(char *name, char **label_called);
int					find_in_lst_called(char *name, t_dbllist *label_called);
void				define_index(char *name, t_data **data, int *i_called, int *i_declared);
int					front_decl(char *lbl_called, t_dbllist **lst_lines, int i_called, int i_declared);
int					back_decl(char *lbl_called, t_dbllist **lst_lines, int i_called, int i_declared);
void				trad_dir_label(t_data **data);
void				tmp_trad_to_str(t_data **data);

void				final_trad(t_data *data, int nb_oct);

/*
**********************  Output  ***********************
*/

void				create_cor(t_data *data, char *file_name);

/*
**********************  Display  ***********************
*/

void				display_file(t_data *data);
void				show_label_lst(t_dbllist *lst);
void				show_lst_recup(t_dbllist *lst);
void				show_tab_char(char **tab);
void				show_trad(t_dbllist *lst);
void				show_lst_hexa(t_dbllist *lst);
void				show_dline(t_dbllist *lst);
void				show_final_trad(char *trad);

/*
**********************  No leaks  **********************
*/

void				free_all_data(t_data *data);
void				free_tab_char(char ***tab);

#endif
