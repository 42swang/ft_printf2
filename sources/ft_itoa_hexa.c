/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:40:57 by swang             #+#    #+#             */
/*   Updated: 2021/06/01 17:19:18 by swang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char			*str;
	unsigned int	idx;

	idx = 0;
	str = malloc((size_t)count + 1);
	if (!str)
		return (NULL);
	str[count] = '\0';
	while (count >= 1)
	{
		str[count - 1] = base[num % 16];
		num = num / 16;
		count--;
	}
	return (str);
}

char		*ft_itoa_hexa(unsigned int x, char *base)
{
	int				count;
	unsigned int	c_num;
	unsigned int	num;

	count = 0;
	c_num = x;
	num = x;
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
