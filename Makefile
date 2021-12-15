CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	push_swap
I_DIR	=	include
L_DIR	=	lib
L_FT	=	libft
LIB		=	-lft

SRC		=	src/main.c	\
			src/check.c	\
			src/push_swap.c \
			src/operation.c \
			src/all.c \
			src/small.c \
			src/small_pt2.c \
			src/big_position.c \

OBJ		=	$(SRC:%.c=%.o)

all: include/push_swap.h $(NAME)

$(NAME): $(L_FT)/libft.a $(OBJ)
	$(CC) -g -o $(NAME) $(OBJ) -I$(I_DIR) -L$(L_DIR) $(LIB)

$(L_FT)/libft.a:
	make -C $(L_FT) && cp -rf $(L_FT)/libft.a lib

%.o: %.c
	$(CC) -g -o $@ -c $< -I$(I_DIR)

clean:
	make clean -C $(L_FT)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(L_FT) && rm -f $(L_DIR)/libft.a
	rm  -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re make_libft
