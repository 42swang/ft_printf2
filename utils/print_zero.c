/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:47:05 by swang             #+#    #+#             */
/*   Updated: 2021/06/01 17:58:55 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_zero(t_info *info)
{
	int		prec_padding;

	prec_padding = 0;
	info->prt_len = 0;
	padding_left(info);
	padding_right(info);
	return (info->ret_len);
}
