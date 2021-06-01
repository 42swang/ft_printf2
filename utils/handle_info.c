/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:46:49 by swang             #+#    #+#             */
/*   Updated: 2021/06/01 15:48:27 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_info(t_info *info)
{
	char	c;

	c = info->type;
	if (info->prec < 0)
	{
		info->flag &= ~DOT;
		info->prec = -1;
	}
	if (info->width < 0)
	{
		info->flag |= MINUS;
		info->width *= -1;
	}
	if (c == 'c' || c == '%')
	{
		info->flag &= ~DOT;
		info->prec = -1;
	}
	if (c == 'c' || c == 'p')
		info->flag &= ~ZERO;
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
	{
		if (info->flag & ZERO && info->flag & DOT && !(info->flag & MINUS))
			info->flag &= ~ZERO;
	}
}
