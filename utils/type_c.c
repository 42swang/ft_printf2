#include "../ft_printf.h"

int	type_char(int c, t_info *info)
{
	if (info->flag & DOT)
	{
		info->flag &= ~DOT;
		info->prec = 0;
	}
	info->prt_len = 1;
	padding_left(info);
	info->ret_len += ft_putchar(c);
	padding_right(info);
	return (info->ret_len);
}
