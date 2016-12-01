/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trad_dir_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		trad_dir_label(int *j, int *i, t_data **data)
{
	t_tmp2	temp;

	ini_tmp2(&temp);
	*j = *i + 1;
	while ((*data)->tmp_trad[*j] != '!')
		*j += 1;
	temp.to_trad = ft_strsub((*data)->tmp_trad, *i + 2, *j - (*i + 2));
	if (!(temp.trad =
		trad_label_called(temp.to_trad, &((*data)->tmp_trad), data)))
		return (0) ;
	modif_trad(*i, *j, temp.trad, &((*data)->tmp_trad));
	ft_strdel(&temp.trad);
	ft_strdel(&temp.to_trad);
	return (1);
}
