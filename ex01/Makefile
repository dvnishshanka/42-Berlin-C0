# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/24 13:09:40 by dnishsha          #+#    #+#              #
#    Updated: 2024/08/24 13:09:42 by dnishsha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
NAME = phonebook
SRCS = src/main.cpp
INCLUDE = -I include

OBJS = $(SRCS:.cpp=.o)

# Compile source files into into object files
%.o: %.cpp
	$(COMPILER) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(COMPILER) $(CFLAGS) $(OBJS) $(INCLUDE) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY : re fclean clean all
