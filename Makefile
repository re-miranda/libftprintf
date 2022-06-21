SRC = libftprintf.c libftprintf__utils.c
OBJ = $(SRCS:%.c=%.o)
HEADER = -I./
CC = cc
AR = ar -rcs
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = ./libft/libft.a

all: $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) ./
	mv ./libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

$(LIBFT):
	make all -C ./libft

clean:
	make clean -C ./libft
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
