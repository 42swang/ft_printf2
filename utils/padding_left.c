/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:46:58 by swang             #+#    #+#             */
/*   Updated: 2021/06/01 16:59:37 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	padding_left(t_info *info)
{
	if (info->flag & MINUS)
		return ;
	if (info->flag & ZERO)
	{
		while (info->width - info->prt_len > 0)
		{
			info->ret_len += ft_putchar('0');
			info->width -= 1;
		}
	}
	else
	{
		while (info->width - info->prt_len > 0)
		{
			info->ret_len += ft_putchar(' ');
			info->width -= 1;
		}
	}
}
