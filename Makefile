NAME = push_swap
NAME_BONUS = checker

SRC = ft_atoi.c ft_split.c linked_list.c utils.c utils_two.c utils_three.c utils_four.c \
    five.c main.c instr_func_one.c instr_func_two.c push_swap.c sort_three.c sort.c is_sorted.c \
	get_next_line.c get_next_line_util.c func_error.c sort_three_func.c

SRC_BONUS = ./bonus/checker_bonus.c ./bonus/ft_atoi_bonus.c ./bonus/ft_split_bonus.c ./bonus/linked_list_bonus.c \
    ./bonus/main_bonus.c ./bonus/instr_func_one_bonus.c ./bonus/instr_func_two_bonus.c ./bonus/acses_bonus.c ./bonus/fun_error_bonus.c\
	./bonus/get_next_line_bonus.c ./bonus/get_next_line_util_bonus.c ./bonus/is_sorted_bonus.c
	
CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


clean :
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all
