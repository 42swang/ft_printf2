/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:44:14 by swang             #+#    #+#             */
/*   Updated: 2021/06/01 18:40:58 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	type_unsigned_num(unsigned int u, t_info *info)
{
	int		prec_padding;
	int		nbr_len;
	char	*u_nbr;

	prec_padding = 0;
	u_nbr = ft_itoa(u);
	if (u == 0 && info->prec == 0)
		return (print_zero(info));
	nbr_len = ft_strlen(u_nbr);
	info->prt_len = ft_strlen(u_nbr);
	if (info->flag & DOT)
		nbr_with_prec(info, nbr_len, &prec_padding);
	padding_left(info);
	while (prec_padding-- > 0)
		info->ret_len += ft_putchar('0');
	info->ret_len += ft_putstr(u_nbr);
	padding_right(info);
	free(u_nbr);
	u_nbr = 0;
	return (info->ret_len);
}
