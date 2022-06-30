SRC = libftprintf.c libftprintf_utils_part1.c libftprintf_utils_part2.c \
	 printf_types_part1.c printf_types_part2.c printf_types_utils.c \
	 ft_atoi_base.c ft_uint_base_str.c ft_uint_str.c ft_sizet_base_str.c
OBJ = $(SRC:%.c=%.o)
HEADER = ./
CC = cc
AR = ar -rcs
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
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
	clear && ./a.out

.PHONY: all clean fclean re
