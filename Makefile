NAME = ./Container

SRC =	main.cpp

all :	$(NAME)

bonus : $(BONUS_NAME)

$(NAME): $(SRC)
		@c++ -Wall -Wextra -Werror -std=c++98 $(SRC) -o $(NAME) -fsanitize=address -g

clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)

re: fclean all