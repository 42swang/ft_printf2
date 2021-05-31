#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define MINUS 1
# define ZERO 2
# define DOT 4
# define WIDTH 8
# define STAR 16
# define TYPE "cspdiuxX%"
# define LOWER "0123456789abcdef"
# define UPPER "0123456789ABCDEF"

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_info
{
	unsigned char	flag;
	int				prec;
	int				width;
	int				ret_len;
	int				prt_len;
	char			type;
}	t_info;

/*----sources----*/
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_putstr(char *str);
int		ft_isdigit(int c);
char	*ft_itoa(long long int n);
char	*ft_itoa_hexa(unsigned int x, char *base);
int		ft_putchar(int c);

/*-----utils----*/
void	init_info(t_info *info);
void	handle_info(t_info *info);
void	padding_left(t_info *info);
void	padding_right(t_info *info);

int		type_percent(va_list ap, t_info *info);
int		type_char(int c, t_info *info);
int		type_str(char *s, t_info *info);
int		type_num(int i, t_info *info);
int		type_unsigned_num(unsigned int u, t_info *info);
int		type_hexadecimal(unsigned int x, t_info *info);
int		type_pointer(unsigned long long p, t_info *info);


void	str_with_prec(t_info *info, int *str_len);
void	nbr_with_prec(t_info *info, int str_len, int *prec_padding);

int		print_zero(t_info *info);


/*---ft_printf---*/
int		ft_printf(const char *fmt, ...);
//static int	check_fmt(va_list ap, const char *fmt);
//void	save_info(va_list ap, t_info *info, char c);
//void	star_and_digit(va_list ap, t_info *info, char c);
//static int	print_info(va_list ap, t_info *info);

#endif
