
#		-*- Makefile -*-	 #

NAME		= libftprintf.a
INC			= ft_printf.h
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rc
RM			= rm -rf

SRCS		= ft_printf.c \
				start_conversion.c \
				string_handler.c \
				flagshandler.c \
				address_converter.c \
				ft_printf_utils.c \
				number_converter.c \
				ft_bonus.c \
				float_converter.c

OBJS		= $(SRCS:.c=.o)

.PHONY:		all re clean fclean bonus

all:	${NAME} 

$(NAME): $(OBJS)
	make -C ./libft 
	cp libft/libft.a libftprintf.a
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(INC) 
	$(CC) $(CFLAGS) -c $< -o $@

clean:	
	make clean -C ./libft
	$(RM) $(OBJS)

fclean:	clean
	make fclean -C ./libft
	$(RM) $(NAME)

re:	fclean all

bonus: re