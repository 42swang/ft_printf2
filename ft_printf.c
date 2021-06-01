/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:49:23 by swang             #+#    #+#             */
/*   Updated: 2021/06/01 18:48:57 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_info(va_list ap, t_info *info)
{
	int		ret;
	char	type;

	ret = 0;
	type = info->type;
	if (type == 'c')
		ret += type_char(va_arg(ap, int), info);
	else if (type == 's')
		ret += type_str(va_arg(ap, char *), info);
	else if (type == 'u')
		ret += type_unsigned_num(va_arg(ap, unsigned int), info);
	else if (type == 'd' || type == 'i')
		ret += type_num(va_arg(ap, int), info);
	else if (type == 'x' || type == 'X')
		ret += type_hexadecimal(va_arg(ap, unsigned int), info);
	else if (type == 'p')
		ret += type_pointer(va_arg(ap, unsigned long long), info);
	else if (type == '%')
		ret += type_percent(info);
	return (ret);
}

void		star_and_digit(va_list ap, t_info *info, char c)
{
	if (c == '*')
	{
		info->flag |= STAR;
		if (info->flag & DOT)
			info->prec = va_arg(ap, int);
		else
			info->width = va_arg(ap, int);
	}
	else if (ft_isdigit(c))
	{
		if (info->flag & DOT)
			info->prec = (10 * info->prec) + (c - '0');
		else
		{
			info->flag |= WIDTH;
			info->width = (10 * info->width) + (c - '0');
		}
	}
}

void		save_info(va_list ap, t_info *info, char c)
{
	if (c == '.')
	{
		info->flag |= DOT;
		info->prec = 0;
	}
	else if (c == '-' && info->flag & DOT)
	{
		info->flag |= MINUS;
		info->flag &= ~DOT;
		info->flag = -1;
		info->width = 0;
	}
	else if (c == '-')
		info->flag |= MINUS;
	else if (c == '*')
		star_and_digit(ap, info, c);
	else if (c == '0' && !(info->flag & WIDTH + DOT))
		info->flag |= ZERO;
	else if (ft_isdigit(c))
		star_and_digit(ap, info, c);
}

static int	check_fmt(va_list ap, t_info *info, const char *fmt)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (fmt[i] != '\0')
	{
		init_info(info);
		while (fmt[i] != '%' && fmt[i] != '\0')
			ret += ft_putchar(fmt[i++]);
		if (fmt[i] == '%')
		{
			i++;
			while (!(ft_strchr(TYPE, fmt[i])) && fmt[i] != '\0')
				save_info(ap, info, fmt[i++]);
			if (fmt[i] == '\0')
				return (0);
			if (ft_strchr(TYPE, fmt[i]))
				info->type = fmt[i++];
			handle_info(info);
			ret += print_info(ap, info);
		}
	}
	return (ret);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_info	*info;
	int		ret;

	ret = 0;
	info = (t_info *)malloc(sizeof(t_info));
	va_start(ap, fmt);
	ret = check_fmt(ap, info, fmt);
	va_end(ap);
	free(info);
	info = 0;
	return (ret);
}
