/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:44:05 by swang             #+#    #+#             */
/*   Updated: 2021/06/01 15:44:08 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	type_char(int c, t_info *info)
{
	info->prt_len = 1;
	padding_left(info);
	info->ret_len += ft_putchar(c);
	padding_right(info);
	return (info->ret_len);
}
