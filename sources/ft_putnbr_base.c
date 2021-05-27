#include "../ft_printf.h"

int	ft_putnbr_base(unsigned int x, char *base)
{
	int		ret;
	char	one;

	ret = 0;
	one = base[x % 16];
	if (x / 16)
		ret += ft_putnbr_base(x / 16, base);
	ret += ft_putchar(one);
	return (ret);
}