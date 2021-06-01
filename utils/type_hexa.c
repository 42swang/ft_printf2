/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_hexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:44:10 by swang             #+#    #+#             */
/*   Updated: 2021/06/01 15:46:05 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	type_hexadecimal(unsigned int x, t_info *info)
{
	int		prec_padding;
	int		nbr_len;
	char	*x_nbr;
	char	*base;

	prec_padding = 0;
	base = UPPER;
	if (info->type == 'x')
		base = LOWER;
	x_nbr = ft_itoa_hexa(x, base);
	if (x == 0 && info->prec == 0)
		return (print_zero(info));
	nbr_len = ft_strlen(x_nbr);
	info->prt_len = ft_strlen(x_nbr);
	if (info->flag & DOT)
		nbr_with_prec(info, nbr_len, &prec_padding);
	padding_left(info);
	while (prec_padding-- > 0)
		info->ret_len += ft_putchar('0');
	info->ret_len += ft_putstr(x_nbr);
	padding_right(info);
	return (info->ret_len);
}
