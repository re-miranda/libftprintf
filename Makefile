SRC = libftprintf.c libftprintf_utils.c printf_types.c
OBJ = $(SRC:%.c=%.o)
HEADER = ./
CC = cc
AR = ar -rcs
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g
NAME = libftprintf.a
LIBFT = ./libft/libft.a

all: $(NAME)

#$(OBJS): $(SRCS)
#	$(CC) $(CFLAGS) -I$(HEADER) $(SRCS)

%.o:	%.c
	$(CC) $(CFLAGS) -c -I$(HEADER) $< -o $(<:%.c=%.o)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) ./
	mv ./libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

$(LIBFT):
	make all -C ./libft

clean:
	make clean -C ./libft
	$(RM) $(OBJ)

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

main: $(NAME)
	$(CC) $(CFLAGS) main.c -L./ -lftprintf
	./a.out

.PHONY: all clean fclean re
