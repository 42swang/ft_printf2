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

static char	*ft_plus(long long int num, int count)
{
	char	*str;

	str = malloc((size_t)count + 1);
	if (!str)
		return (NULL);
	str[count] = '\0';
	while (count >= 1)
	{
		str[count - 1] = (num % 10) + 48;
		num = num / 10;
		count--;
	}
	return (str);
}

char	*ft_itoa(long long int n)
{
	int				count;
	long long int	c_num;
	long long int	num;

	count = 0;
	c_num = n;
	num = n;
	if (n < 0)
	{
		c_num *= -1;
		num *= -1;
	}
	while (1 <= c_num)
	{
		c_num = (c_num / 10);
		count++;
	}
	if (num > 0)
		return (ft_plus(num, count));
	else
		return (ft_zero(count));
}
