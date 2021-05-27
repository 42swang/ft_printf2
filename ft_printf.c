#include "ft_printf.h"
#include <stdio.h>

/*void	print_flag(t_info *info)
{
	printf("[%d]\n", info->width);
	printf("[%d]\n", info->precision);
	printf("[%d]\n", info->flag);
}*/

int	print_module(va_list ap, t_info *info)
{
	char	type;
	int		ret;

	type = info->type;
	ret = 0;
	if (type == 'c')
		ret = print_char(va_arg(ap, int), info);
	else if (type == 's')
		ret = print_str(va_arg(ap, char *), info);
	else if (type == 'd' || type == 'i')
		ret = print_num(va_arg(ap, int), info);
	else if (type == 'u')
		ret = print_unsigned_num(va_arg(ap, unsigned int), info);
	else if (type == 'x' || type == 'X')
		ret = print_hexadecimal(va_arg(ap, unsigned int), info);
	else if (type == 'p')
		ret = print_ptr(va_arg(ap, unsigned int), info);
	else if (type == '%')
		ret = print_percent(info);
	return (ret);
}


void	check_flag(t_info *info, const char *input, int *i)
{
	if (ft_strchr(input, '-'))
		info->flag |= MINUS;
	while (!ft_strchr(TYPE, input[*i]) && input[*i] != '\0')
	{


	}
}

int	check_input(va_list ap, const char *input)
{
	t_info	*info;
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	info = (t_info *)malloc(sizeof(t_info));
	while (input[i] != '\0')
	{
		new_info(info);
		while (input[i] != '%' && input[i] != '\0')
		{
			ft_putchar(input[i++]);
			ret++;
		}
		if (input[i] == '%')
		{
			i++;
			check_flag(info, input, &i);
			if (ft_strchr("%csdiuxXp", input[i]))
				info->type = input[i];
		//	print_flag(info);
		//	handle_flag(info);
			ret += print_module(ap, info);
			i++;
		}
	}
	return (ret);
}

int	ft_printf(const char *input, ...)
{
	int	ret;
	va_list ap;

	ret = 0;
	va_start(ap, input);
	ret = check_input(ap, input);
	va_end(ap);
	return (ret);
}
