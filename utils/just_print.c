#include "../ft_printf.h"

void	just_print(const char *format, int *i, t_info *info)
{
	while (format[*i] != '%' && format[*i] != '\0')
	{
		ft_putchar(format[*i]);
		(*i)++;
		info->ret_len += 1;
	}
}
