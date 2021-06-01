/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:47:02 by swang             #+#    #+#             */
/*   Updated: 2021/06/01 15:47:36 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	padding_right(t_info *info)
{
	if (!(info->flag & MINUS))
		return ;
	while (info->width - info->prt_len > 0)
	{
		info->ret_len += ft_putchar(' ');
		info->width -= 1;
	}
}
