#include "../ft_printf.h"

int	type_str(char *s, t_info *info)
{
	int		i;
	int		str_len;
	char	*str;

	if (s == NULL)
	{
		str = "(null)";
		s = str;
	}
	i = 0;
	str_len = ft_strlen(s);
	info->prt_len = ft_strlen(s);
	if (info->flag & DOT)
		str_with_prec(info, &str_len);
	padding_left(info);
	while (str_len > 0)
	{
		info->ret_len += ft_putchar(s[i++]);
		str_len--;
	}
	padding_right(info);
	return (info->ret_len);
}
