NAME = sudoku

SRCS_DIR = ./srcs/

FLAGS = -Wall -Wextra -Werror

SRCS = sudoku \
		solve \
		check_put


HEADER = -I./include

OBJ =	$(addprefix obj/, $(addsuffix .o, $(SRCS)))

all: $(NAME)

obj/%.o: srcs/%.c
	@gcc -c $< $(HEADER) -o $@

$(NAME): obj $(OBJ)
	@tput setaf 7; tput bold; echo "Compiling sudoku"
	@gcc $(FLAGS) $(OBJ) $(HEADER) -o $(NAME)
	@tput setaf 2; tput bold; echo "DONE sudoku"

obj:
	@mkdir obj

clean:
	@rm -rf obj
	@tput setaf 6; tput bold; echo "DONE Clean!"

fclean: clean
	@rm -f $(NAME)
	@tput setaf 6; tput bold; echo "DONE Fclean!"

re: fclean all
.PHONY: all clean fclean re