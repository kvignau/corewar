/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 11:34:39 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/11 14:00:37 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	t_list	*findfd(int const fd, t_list *lst)
{
	int		found;
	t_list	*tmp;

	tmp = lst;
	found = 0;
	while (tmp != NULL && !found)
	{
		if (((t_lines *)(tmp->content))->fd == fd)
			found = 1;
		else
			tmp = tmp->next;
	}
	if (found == 0)
		tmp = NULL;
	return (tmp);
}

static	void	filllines(char *buf, int const fd, t_list **lst)
{
	t_lines		stlines;
	t_list		*tmp;
	char		*tmplines;

	stlines.lines = NULL;
	stlines.fd = 0;
	if ((tmp = findfd(fd, *lst)))
	{
		if (LINES)
		{
			tmplines = LINES;
			LINES = ft_strjoin(tmplines, buf);
			free(tmplines);
		}
		else
			LINES = ft_strdup(buf);
	}
	else
	{
		stlines.lines = ft_strdup(buf);
		stlines.fd = fd;
		ft_lstadd(lst, ft_lstnew(&stlines, sizeof(t_lines)));
	}
}

static void		ft_delelem(t_list **lst, t_list *to_del)
{
	t_list		*tmp;
	t_list		*next;
	t_list		*prev;

	tmp = *lst;
	prev = NULL;
	while (tmp)
	{
		if (tmp == to_del)
		{
			next = tmp->next;
			ft_strdel(&(LINES));
			ft_memdel((void **)tmp);
			if (prev == NULL)
				*lst = next;
			else
				prev->next = next;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	ft_memdel((void **)&prev);
}

static void		sendingline(t_list **lst, int const fd, char **line)
{
	int		i;
	char	*endline;
	t_list	*tmp;
	char	*tmplines;

	i = 0;
	tmp = findfd(fd, *lst);
	endline = ft_strchr(LINES, '\n');
	*line = endline ? ft_strnew(endline - LINES) \
						: ft_strnew(ft_strlen(LINES));
	while (LINES[i] != '\n' && LINES[i] != '\0')
	{
		(*line)[i] = (LINES)[i];
		i++;
	}
	if ((LINES)[i + 1])
	{
		tmplines = LINES;
		LINES = ft_strsub(tmplines, i + 1, ft_strlen(tmplines) - (i + 1));
		free(tmplines);
	}
	else
		ft_delelem(lst, tmp);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*lst = NULL;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	while (line != NULL && (ret = read(fd, buf, BUFF_SIZE)) > 0
	&& ft_strchr(buf, '\n') == NULL)
	{
		buf[ret] = '\0';
		filllines(buf, fd, &lst);
	}
	if (ret == 0 && line != NULL)
	{
		if (findfd(fd, lst) == NULL)
			return (0);
		sendingline(&lst, fd, line);
	}
	else if (ft_strchr(buf, '\n') != NULL && line != NULL)
	{
		buf[ret] = '\0';
		filllines(buf, fd, &lst);
		sendingline(&lst, fd, line);
	}
	else
		return (-1);
	return (1);
}
