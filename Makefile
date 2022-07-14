NAME = Container

SRC =	main.cpp

FLAGS = -std=c++98 -Wall -Wextra -Werror -pedantic -g

all :	$(NAME)

bonus : $(BONUS_NAME)

$(NAME): $(SRC)
		@c++  $(SRC) -o $(NAME) -fsanitize=address -g

clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)

re: fclean all