NAME = 		libftprintf.a
CC = 		gcc
CFLAGS = 	-Wall -Werror -Wextra -Wunused-variable
SRCS = ft_printf.c ft_putchar.c \
       ft_putnbr.c ft_putstr.c \
       ft_strlen.c \

OBJS = 		$(SRCS:.c=.o)

B_OBJS =  	$(SRCS_B:.c=.o)

all : 		$(NAME)

$(NAME) : 	$(OBJS)
			$(AR) rcs $(NAME) $(OBJS)

clean : 
			rm -f $(OBJS)

fclean : 	clean
			rm -f $(NAME)

re : 		fclean all

.PHONY : 	all bonus clean fclean re