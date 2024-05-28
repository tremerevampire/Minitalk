NAMEC =			client
NAMES =			server

CC = 			gcc
CFLAGS =		-Wall -Werror -Wextra -g3

SRCSC =			./src/client.c
SRCSS =			./src/server.c

OBJSC =			$(SRCSC:.c=.o)
OBJSS =			$(SRCSS:.c=.o)


FTLIBFT =		./libft/
LIBFT = 		./libft/libft.a

FTPRINTF =		./ftPrintf
PRINTF = 		./ftPrintf/libftprintf.a

RM =			rm -f

all : 		$(LIBFT) $(PRINTF) $(NAMEC) $(NAMES)

$(LIBFT) :	
			@make -C $(FTLIBFT)
			@make bonus -C $(FTLIBFT)

$(PRINTF) :
			@make -C $(FTPRINTF)

$(NAMEC) : 	$(OBJSC)
			@echo "Compiling client..."
			@$(CC) $(CFLAGS) -o $(NAMEC) $(OBJSC) -L$(FTLIBFT) -lftprintf -L$(FTPRINTF) -lft
			@echo "Done"

$(NAMES) :	$(OBJSS)
			@echo "Compiling server..."
			@$(CC) $(CFLAGS) -o $(NAMES) $(OBJSS) -L$(FTLIBFT) -lftprintf -L$(FTPRINTF) -lft
			@echo "Done"

clean : 
			@echo "Cleaning..."
			@$(RM) $(OBJSC) $(OBJSS) 
			@make clean -C $(FTLIBFT)
			@make clean -C $(FTPRINTF)
			@echo "Done"

fclean : 	clean
			@echo "Full cleaning..."
			@$(RM) $(NAMEC) $(NAMES) 
			@make fclean -C $(FTLIBFT)
			@make fclean -C $(FTPRINTF)
			@echo "Done"

re : 		fclean all

.PHONY : 	all bonus clean fclean re