NAME		=	containers

SRCS		=	test.cpp				\

SRCS_DIR	=	srcs

CC			=	c++

RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -g -Iinc #-I~/Desktop/termios/inc

OBJS			=	$(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))

OBJS_DIR		=	obj

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.cpp
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS_DIR) logFT logSTD

fclean:	clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re