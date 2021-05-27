#include "../ft_printf.h"

int	type_str(char *s, t_info *info)
{
	int i;

	i = 0;
	if (info->flag & DOT)
		care_prec(info, s);
	padding_left(info);
	while (info->prt_len > 0)
	{
		info->ret_len += ft_putchar(s[i++]);
		info->prt_len -= 1;
	}
	padding_right(info);
	return (info->ret_len);
}
