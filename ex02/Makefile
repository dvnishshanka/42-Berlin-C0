# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/24 13:26:01 by dnishsha          #+#    #+#              #
#    Updated: 2024/08/24 13:26:04 by dnishsha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
NAME = accounts
SRCS = tests.cpp Account.cpp
INCLUDE = -I .

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
