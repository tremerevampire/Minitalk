NAMEC =			client
NAMES =			server
NAMEC_B =		client_bonus
NAMES_B =		server_bonus

CC = 			gcc
CFLAGS =		-Wall -Werror -Wextra -g3

SRCSC =			./src/client.c
SRCSS =			./src/server.c
SRCSC_B =		./src/client_bonus.c
SRCSS_B = 		./src/server_bonus.c

OBJSC =			$(SRCSC:.c=.o)
OBJSS =			$(SRCSS:.c=.o)
B_OBJSC =		$(SRCSC_B:.c=.o)
B_OBJSS =		$(SRCSS_B:.c=.o)

FTLIBFT =		../libft
LIBFT = 		../libft/libft.a

FTPRINTF =		../ftPrintf
PRINTF = 		../ftPrintf/libftprintf.a

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

bonus : 	$(LIBFT) $(PRINTF) $(NAMEC_B) $(NAMES_B) 

$(NAMEC_B) : $(B_OBJSC)
			@echo "Compiling client_bonus"
			@$(CC) $(CFLAGS) -o $(NAMEC_B) $(B_OBJSC) -L$(FTLIBFT) -lftprintf -L$(FTPRINTF) -lft
			@echo "Done"

$(NAMES_B) : $(B_OBJSS)
			@echo "Compiling client_bonus"
			@$(CC) $(CFLAGS) -o $(NAMES_B) $(B_OBJSS) -L$(FTLIBFT) -lftprintf -L$(FTPRINTF) -lft
			@echo "Done"

clean : 
			@echo "Cleaning..."
			@$(RM) $(OBJSC) $(B_OBJSC) $(OBJSS) $(B_OBJSS)
			@make clean -C $(FTLIBFT)
			@make clean -C $(FTPRINTF)
			@echo "Done"

fclean : 	clean
			@echo "Full cleaning..."
			@$(RM) $(NAMEC) $(NAMES) $(NAMEC_B) $(NAMES_B)
			@make fclean -C $(FTLIBFT)
			@make fclean -C $(FTPRINTF)
			@echo "Done"

re : 		fclean all

.PHONY : 	all bonus clean fclean re