PROGRAMNAME = push_swap

CC = gcc -Wall -Werror -Wextra
SOURCE = index_changer.c linked_list_processes.c process_desigm_for_b_next.c \
		process_design_for_b.c processes.c processes_designed.c \
		push_processes.c push_swap.c push_swap_utils.c \
		reverse_rotate_processes.c rotate_processes.c sort_for_four.c \
		sort_for_to.c sort_for_tw.c sort_new.c \
		sort_new_utils.c sort_new_utils_next.c swap_processes.c

OBJS = index_changer.o linked_list_processes.o process_desigm_for_b_next.o \
		process_design_for_b.o processes.o processes_designed.o \
		push_processes.o push_swap.o push_swap_utils.o \
		reverse_rotate_processes.o rotate_processes.o sort_for_four.o \
		sort_for_to.o sort_for_tw.o sort_new.o \
		sort_new_utils.o sort_new_utils_next.o swap_processes.o

all : $(PROGRAMNAME)

$(PROGRAMNAME) :
	$(CC) $(SOURCE) -o $(PROGRAMNAME)
	$(CC) -c $(SOURCE)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(PROGRAMNAME)

re : fclean all
