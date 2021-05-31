NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar rcs

SRCS = sources/ft_isdigit.c\
		sources/ft_itoa.c\
		sources/ft_itoa_hexa.c\
		sources/ft_putchar.c\
		sources/ft_putstr.c\
		sources/ft_strchr.c\
		sources/ft_strlen.c\
		utils/care_prec.c\
		utils/handle_info.c\
		utils/init_info.c\
		utils/padding_left.c\
		utils/padding_right.c\
		utils/type_char.c\
		utils/type_str.c\
		utils/type_num.c\
		utils/type_u_num.c\
		utils/type_hexa.c\
		utils/print_zero.c\
		ft_printf.c

OBJS = $(SRCS:.c=.o)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)
	
re:		fclean all

.PHONY:	all clean fclean re