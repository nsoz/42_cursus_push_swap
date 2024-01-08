PROGRAMNAME = push_swap

CC = gcc -Wall -Werror -Wextra
SOURCE = *.c

all : $(PROGRAMNAME)

$(PROGRAMNAME) :
	$(CC) $(SOURCE) -o $(PROGRAMNAME)

clean :
	rm -rf $(PROGRAMNAME)

fclean : 
	rm -rf $(PROGRAMNAME)

re : fclean all
