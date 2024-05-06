NAMEC = 		client
NAMES =			server
NAMEC_B =		client_bonus
NAMES_B =		server_bonus
CC = 		gcc
CFLAGS = 	-Wall -Werror -Wextra
SRCSC =	./src/client.c
SRCSS =	./src/server.c

SRCSC_B = ./src/client_bonus.c
SRCSS_B = ./src/server_bonus.c

OBJSC = 		$(SRCSC:.c=.o)
OBJSS =			$(SRCSS:.c=.o)

B_OBJSC =  	$(SRCSC_B:.c=.o)
B_OBJSS =	$(SRCSS_B:.c=.o)

all : 		$(NAMEC) $(NAMES)

$(NAMEC) : 	$(OBJSC)
			$(CC) $(CFLAGS) $(NAMEC) $(OBJSC)

$(NAMES) :	$(OBJSS)
			$(CC) $(CFLAGS) $(NAMES) $(OBJSS)

bonus : 	$(B_OBJSC) $(B_OBJSS)
			$(CC) $(CFLAGS) $(NAMEC_B) $(B_OBJSC)
			$(CC) $(CFLAGS) $(NAMES_B) $(B_OBJSS)

clean : 
			rm -f $(OBJSC) $(B_OBJSC) $(OBJSS) $(B_OBJSS)

fclean : 	clean
			rm -f $(NAMEC) $(NAMES) $(NAMEC_B) $(NAMES_B)

re : 		fclean all

.PHONY : 	all bonus clean fclean re