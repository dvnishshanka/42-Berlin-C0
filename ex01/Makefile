CLANG = clang++
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = phonebook
SRCS = src/main.cpp
INCLUDE = -I include

OBJS = $(SRCS:.cpp=.o)

# Compile source files into into object files
%.o: %.cpp
	$(CLANG) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CLANG) $(CFLAGS) $(OBJS) $(INCLUDE) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY : re fclean clean all
