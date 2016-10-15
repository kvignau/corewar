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

void	trad_name_instruct(int op_code, t_recup *recup)
{
	t_hexa		hex;
	char		*tmp;
	char		*zero;

	ft_putstr("trad_name_instruct\n");
	ft_bzero(&hex, sizeof(t_hexa));
	tmp = ft_itoabase_imax(op_code, 16);
	hex_to_lower(&tmp);
	zero = ft_strdup("0");
	if (ft_strlen(op_tab[op_code - 1].name) == 1)
		hex.hexa = ft_strjoin(zero, tmp);
	else
		hex.hexa = ft_strdup(tmp);
	ft_strdel(&zero);
	ft_strdel(&tmp);
	// ft_lstdbladd_head(recup->lst_hexa, &hex, sizeof(t_hexa));
}

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

void	sum_args(t_recup *recup)
{
	int		i;
	int		type;
	int		sum;
	t_hexa	hex;

	i = 0;
	type = 0;
	sum = 0;
	ft_bzero(&hex, sizeof(t_hexa));
	while (recup->args_tab[i])
	{
		type = 0;
		if ((type = define_type_args(recup->args_tab[i])) == 0)
			return ;
		if (i == 0)
			sum = type << 6;
		else if (i == 1)
			sum = sum | (type << 4);
		else if (i == 2)
			sum = sum | (type << 2);
		else
			return ;
		i++;
	}
	hex.hexa = ft_itoabase_imax(sum, 16);
	// ft_lstdbladd_head(recup->lst_hexa, &hex, sizeof(t_hexa));
}
