CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	push_swap
I_DIR	=	include
L_FT	=	libft
LIB		=	-lft
A_LIB	=	libft

SRC		=	src/main.c	\
			src/check.c	\
			src/push_swap.c \
			src/operation.c \
			src/all.c \
			src/small.c \
			src/small_pt2.c \
			src/big_position.c \
			src/qs_utils.c \
			src/qs_first_chunk.c \
			src/qs_chunk.c \
			src/init.c \

OBJ		=	$(SRC:%.c=%.o)

all: include/push_swap.h $(NAME)

$(NAME): $(L_FT)/libft.a $(OBJ)
	$(CC) -g -o $(NAME) $(OBJ) -I$(I_DIR) -L$(A_LIB) $(LIB)

$(L_FT)/libft.a:
	make -C $(L_FT) 

%.o: %.c
	$(CC) -g -o $@ -c $< -I$(I_DIR)

clean:
	make clean -C $(L_FT)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(L_FT)
	rm  -rf $(NAME)

re: fclean all

.PHONY: all run clean fclean re make_libft
