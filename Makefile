SRC_COMMON = _find_specification.c \
	_flag_precision.c \
	_flag_width.c \
	_types_part1.c \
	_types_part2.c \
	ft_uint_base_str.c \
	ft_uint_str.c \
	ft_sizet_base_str.c
SRC_M = ft_printf.c $(SRC_COMMON)
SRC_B = ft_printf_bonus.c $(SRC_COMMON)
OBJ_M = $(SRC_M:%.c=%.o)
OBJ_BONUS = $(SRC_B:%.c=%.o)
HEADER = ./
CC = cc
AR = ar -rcs
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
NAME_M = libftprintf.a
NAME_B = libftprintf_bonus.a
LIBFT = ./libft/libft.a

all: $(NAME_M)

%.o:	%.c
	$(CC) $(CFLAGS) -c -I$(HEADER) $< -o $(<:%.c=%.o)

$(NAME_M): $(OBJ_M) $(LIBFT)
	cp $(LIBFT) ./
	mv ./libft.a $(NAME_M)
	$(AR) $(NAME_M) $(OBJ_M)

$(LIBFT):
	make all -C ./libft

bonus: $(OBJ_BONUS) $(LIBFT)
	cp $(LIBFT) ./
	mv ./libft.a $(NAME_B)
	$(AR) $(NAME_B) $(OBJ_BONUS)

clean:
	make clean -C ./libft
	$(RM) $(OBJ_M)
	$(RM) $(OBJ_BONUS)

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME_M) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re
