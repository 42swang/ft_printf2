/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:46:55 by swang             #+#    #+#             */
/*   Updated: 2021/06/01 15:46:56 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	init_info(t_info *info)
{
	info->flag = 0;
	info->prec = -1;
	info->width = 0;
	info->ret_len = 0;
	info->prt_len = 0;
	info->type = 0;
}
