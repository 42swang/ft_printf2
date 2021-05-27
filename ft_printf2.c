/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:43:01 by swang             #+#    #+#             */
/*   Updated: 2021/05/28 04:41:12 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_format(t_info *info, va_list ap)
{
	char	type;

	type = info->type;
	if (type == 'c')
		info->ret_len += type_char(va_arg(ap, int), info);
	else if (type == 's')
		info->ret_len += type_str(va_arg(ap, char *), info);
	/*
	else if (type == 'd' || type == 'i')
		ret = type_num(va_arg(ap, int), info);
	else if (type == 'u')
		ret = type_unsigned_num(va_arg(ap, unsigned int), info);
	else if (type == 'x' || type == 'X')
		ret = type_hexadecimal(va_arg(ap, unsigned int), info);
	else if (type == 'p')
		ret = type_ptr(va_arg(ap, unsigned int), info);
	else if (type == '%')
		ret = type_percent(info);
*/
}

void	check_flag(char c, t_info *info, va_list ap)
{
	if (c == '0' && !(info->flag & WIDTH) && !(info->flag & DOT))
		info->flag |= ZERO;
	else if (ft_isdigit(c))
	{
		if (info->flag & DOT)
			info->prec = (10 * info->prec) + (c - '0');
		else
		{
			info->width = (10 * info->width) + (c - '0');
			info->flag |= WIDTH;
		}
	}
	else if (c == '*')
	{
		if (info->flag & DOT)
			info->prec = va_arg(ap, int);
		else
			info->width = va_arg(ap, int);
	}
}

void	check_format(const char *format, va_list ap, t_info *info, int *i)
{
	if (format[*i] != '%')
		return ;
	if (ft_strchr(format, '-'))
		info->flag |= MINUS;
	(*i)++;
	while (format[*i] != '\0' && !(ft_strchr(TYPE, format[*i])))
	{
		if (format[*i] == '.')
		{
			info->flag |= DOT;
			info->prec = 0;
			if (format[++(*i)] == '-')
			{
				info->flag &= ~DOT;
				info->prec = -1;
			}
		}
		check_flag(format[*i], info, ap);
		(*i)++;
	}
	if (ft_strchr(TYPE, format[(*i)]))
		info->type = format[*i];
	return ;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_info	*info;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (-1);
	va_start(ap, format);
	while (format[i] != '\0')
	{
		init_info(info);
		just_print(format, &i, info);
		check_format(format, ap, info, &i);
		print_format(info, ap);
		i++;
	}
	va_end(ap);
	free(info);
	info = 0;
	return (ret);
}
