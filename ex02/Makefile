NAME = ex02_buro
CC = c++ -Wall -Wextra -Werror -std=c++98

SRC = main.cpp AForm.cpp Bureaucrat.cpp PresidentialPardonForm.cpp\
		RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re