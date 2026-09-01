NAME = span
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Span.cpp
HEADER = Span.hpp
OBJ = $(SRC:%.cpp=%.o)
all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re