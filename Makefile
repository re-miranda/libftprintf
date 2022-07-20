SRC = ft_printf.c _utils_part1.c _utils_part2.c \
	 _types_part1.c _types_part2.c _types_utils.c \
	 _uint_base_str.c _uint_str.c _sizet_base_str.c
SRC_BONUS = ft_printf_bonus.c _utils_part1.c _utils_part2.c \
	 _types_part1.c _types_part2.c _types_utils.c \
	 _uint_base_str.c _uint_str.c _sizet_base_str.c
OBJ = $(SRC:%.c=%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=%.o)
HEADER = ./
CC = cc
AR = ar -rcs
RM = rm -rf
CFLAGS = -Wall -Wextra -g
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

bonus: $(OBJ_BONUS) $(LIBFT)
	cp $(LIBFT) ./
	mv ./libft.a $(NAME)
	$(AR) $(NAME) $(OBJ_BONUS)

main: $(NAME)
	$(CC) $(CFLAGS) main.c -L./ -lftprintf
	clear && ./a.out

.PHONY: all clean fclean re
