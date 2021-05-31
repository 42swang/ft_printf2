#include "../ft_printf.h"

static char	*ft_zero(int count)
{
	char	*str;

	str = malloc(count + 2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*ft_plus(unsigned int num, int count, char *base)
{
	char	*str;

	str = malloc((size_t)count + 1);
	if (!str)
		return (NULL);
	str[count] = '\0';
	while (count >= 1)
	{
		//나눗셈이 제대로 안됨.. num % 16 에서 오류남;
		str[count - 1] = base[num % 16];
		num = num / 10;
		count--;
	}
	printf("%s\n", str);
	return (str);
}

char	*ft_itoa_hexa(unsigned int n, char *base)
{
	int				count;
	unsigned int	c_num;
	unsigned int	num;

	count = 0;
	c_num = n;
	num = n;
	while (1 <= c_num)
	{
		c_num = (c_num / 16);
		count++;
	}
	if (num > 0)
		return (ft_plus(num, count, base));
	else
		return (ft_zero(count));
}
