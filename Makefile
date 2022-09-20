NAME      = server
NAME1     = client
SRCS_SRV  = server.c
SRCS_CL   = client.c
OBJCS_SRV = server.o
OBJCS_CL  = client.o
CC    	  = cc
RM    	  = rm -f
FLAGS 	  = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME) $(NAME1)

$(NAME) : $(OBJCS_SRV)
	$(CC) $(FLAGS) -o $(NAME) $(OBJCS_SRV)

$(NAME1) : $(OBJCS_CL)
	$(CC) $(FLAGS) -o $(NAME1) $(OBJCS_CL)

clean :
	$(RM) $(OBJCS_SRV)
	$(RM) $(OBJCS_CL)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(NAME1)

re : fclean all

.PHONY: all clean fclean re
