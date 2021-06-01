/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:44:21 by swang             #+#    #+#             */
/*   Updated: 2021/06/01 17:13:19 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	type_pointer(unsigned long long p, t_info *info)
{
	int		prec_padding;
	int		ptrstr_len;
	char	*pointer;

	prec_padding = 0;
	pointer = ft_itoa_ptr(p, LOWER);
	ptrstr_len = ft_strlen(pointer);
	info->prt_len = ft_strlen(pointer) + 2;
	ptr_with_prec(info, ptrstr_len, &prec_padding);
	if (p == 0 && info->prec == 0)
		info->prt_len = 2;
	padding_left(info);
	info->ret_len += ft_putstr("0x");
	while (prec_padding-- > 0)
		info->ret_len += ft_putchar('0');
	if (p != 0 || (p == 0 && info->prec != 0))
		info->ret_len += ft_putstr(pointer);
	padding_right(info);
	return (info->ret_len);
}
