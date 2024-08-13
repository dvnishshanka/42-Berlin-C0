CFLAGS = -Wall -Wextra -Werror
NAME = megaphone
SRC = megaphone.cpp
RM = rm -f
CLANG = clang++

OBJS = $(SRC:.cpp=.o)

# Compile source files into into object files
%.o: %.cpp
	$(CLANG) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CLANG) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : re fclean all clean
