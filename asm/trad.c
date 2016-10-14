/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trad.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:59:53 by mpaincha          #+#    #+#             */
/*   Updated: 2016/09/29 16:14:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	trad_args(t_recup *recup)
{
	t_hexa					hex;
	int						i;
	static const t_trad		ft_trad[] = {trad_reg, trad_dir, trad_ind};
	t_trad					trad;

	ft_bzero(&hex, sizeof(t_hexa));
	recup->lst_hexa = ft_lstdblnew();
	i = 0;
	ft_putstr("Trad_args\n");
	while (recup->args_tab[i])
	{
		ft_printf("recup->args_tab[i] : %s\n", recup->args_tab[i]);
		trad = ft_trad[define_trad_fct(recup->args_tab[i])];
		trad(recup->args_tab[i], &hex);
		i++;
		ft_lstdbladd_head(recup->lst_hexa, &hex, sizeof(t_hexa));
	}
}

char	*sum_args(char **args_tab)
{
	int		i;
	int		type;
	int		sum;

	i = 0;
	type = 0;
	while (args_tab[i])
	{
		type = 0;
		if ((type = define_type_args(args_tab[i])) == 0)
			return (0);
		if (i == 0)
			sum = type << 6;
		else if (i == 1)
			sum = sum | (type << 4);
		else if (i == 2)
			sum = sum | (type << 2);
		else
			return (0);
		i++;
	}
	return (ft_itoabase_imax(sum, 16));
}
