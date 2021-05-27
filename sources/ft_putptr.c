#include "../ft_printf.h"

int	ft_putptr(unsigned int p, char *base, int count)
{
	int	ret;
	char	one;

	ret = 0;
	one = base[p % 16];
	if (p == '\0')
		return (0);
	if (p / 16)
	{
		count++;
		ret += ft_putptr(p / 16, base, count);
	}
	while (p / 16 == 0 && count < 9)
	{
		ft_putchar('0');
		count++;
		ret++;
	}
	ret += ft_putchar(one);
	return (ret);
}