CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=push_swap
SRC=ps_utils.c ps_utils1.c ps_sm.c ps_parser.c ps_parser1.c ps_helpers.c push_swap.c ps_helpers1.c
OBJ=$(SRC:.c=.o)
BONUS_S=Bonus/checker.c Bonus/checker_ops.c Bonus/checker_ops1.c Bonus/checker_parser.c Bonus/checker_helpers.c Bonus/gnl/get_next_line.c Bonus/gnl/get_next_line_utils.c
BONUS_O=$(BONUS_S:.c=.o)

all:$(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):$(OBJ)
	make -C libft/
	gcc $(OBJ) libft/libft.a -o $(NAME)

checker:$(BONUS_O)
	make -C libft/
	gcc ${BONUS_O} libft/libft.a -o checker

bonus:checker

clean:
	make clean -C libft/
	rm -f $(OBJ) $(BONUS_O)

fclean:clean
	make fclean -C libft/
	rm -f $(NAME) checker

re:fclean all
