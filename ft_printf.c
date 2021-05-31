#include "ft_printf.h"

static int	print_info(va_list ap, t_info *info)
{
	int		ret;
	char	type;
	
	ret = 0;
	type = info->type;
	if (type == 'c')
		ret += type_char(va_arg(ap, int), info);
	else if (type == 's')
		ret += type_str(va_arg(ap, char *), info);
	else if (type == 'u')
		ret += type_unsigned_num(va_arg(ap, unsigned int), info);
	else if (type == 'd' || type == 'i')
		ret += type_num(va_arg(ap, int), info);
	else if (type == 'x' || type == 'X')
		ret += type_hexadecimal(va_arg(ap, unsigned int), info);
	/*
	else if (type == 'p')
		ret += type_pointer(ap, info);
	else if (type == '%')
		ret += type_percent(info);
	*/
	return (ret);
}

void	star_and_digit(va_list ap, t_info *info, char c)
{
	if (c == '*')
	{
		info->flag |= STAR;
		if (info->flag & DOT) //좌에서 우로 읽기 떄문에 dot잇으면 너비아님
			info->prec = va_arg(ap, int);
		else
			info->width = va_arg(ap, int);
	}
	else if (ft_isdigit(c))
	{
		if (info->flag & DOT)
			info->prec = (10 * info->prec) + (c - '0');
		else
		{
			info->flag |= WIDTH;
			info->width = (10 * info->width) + (c - '0');
		}
	}
}

void	save_info(va_list ap, t_info *info, char c)
{
	if (c == '.')
	{
		info->flag |= DOT;
		info->prec = 0;
	}
	else if (c == '-' && info->flag & DOT) //dot이후에 음수가 나오면 숫자를 너비로 취급
	{
		info->flag |= MINUS;
		info->flag &= ~DOT; //플래그 끄기
		info->flag = -1; // 꺼진상태는 기본값 -1
		info->width = 0; //새로운 너비 적용하기 위해서 0으로.. (-만나오고 숫자가 안나오면 어떻게 작동할지 정확하게는 아직 모름)...
	}
	else if (c == '-')
		info->flag |= MINUS;
	else if (c == '*')
		star_and_digit(ap, info, c);
	else if (c == '0' && !(info->flag & WIDTH + DOT))
		info->flag |= ZERO;
	else if (ft_isdigit(c))
		star_and_digit(ap, info, c);
}

static int	check_fmt(va_list ap, const char *fmt)
{
	int	i;
	int	ret;
	t_info	*info;

	i = 0;
	ret = 0;
	info = (t_info *)malloc(sizeof(t_info));
	while (fmt[i] != '\0') //1번 : 이부분은 모든 문자열이 끝날때까지 반복하는 구간
	{
		init_info(info);
		while (fmt[i] != '%' && fmt[i] != '\0') // 2: %가 나오기 전까지 출력 단,printf("test\n") 처럼 단순출력일 경우를 고려.
			ret += ft_putchar(fmt[i++]);
		if (fmt[i] == '%') // 위의 while문에서 널문자여도 1번 안에 들어온 이상 전부 작동하고 넘어감. %인지 체크하기
		{	
			i++;
			while (!(ft_strchr(TYPE, fmt[i])) && fmt[i] != '\0')//%다음에 바로 서식지정자가 아니면 플래그 관련된거라서 보내기
				save_info(ap, info, fmt[i++]); //인덱스를 모두 여기서 넘김
			if (ft_strchr(TYPE, fmt[i]))//위에서 ++하고 넘어온 인덱스의 문자가 서식지정자인지 체크하기
				info->type = fmt[i++]; //서식지정자가 나오면 저장해주자
			handle_info(info);
			ret += print_info(ap, info);//저장 다하고 넘어왔으니 출력해주자 printf("abc%defg", 100); 이라면 abc%d 까지 처리완료.
		}
	}
	return (ret);
}

int			ft_printf(const char * fmt, ...)
{
	va_list	ap;
	int		ret;

	ret = 0;
	va_start(ap, fmt);
	ret = check_fmt(ap, fmt);
	va_end(ap);
	return (ret);
}
