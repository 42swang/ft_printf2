#include "../ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i])
		ret += ft_putchar(str[i++]);
	return (ret);
}