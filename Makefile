NAME =	Fractol

SRC =	ini.c \
		main.c \
		burning.c \
		julia.c \
		manderbrot.c \
		nuancier.c \
		pixel.c \
		zoom.c \
		key.c

LIBS =	-framework OpenGL -framework Appkit minilibx_macos/libmlx.a libft/libft.a

OBJ =	$(SRC:.c=.o)

.SILENT :

all : $(NAME)

$(NAME) : 
		make -C libft/
		make -C minilibx_macos/
		gcc -c $(SRC)
		gcc $(LIBS) $(OBJ) -o $(NAME)

clean :
	$(MAKE) -C libft/ clean
	/bin/rm -f $(OBJ)

fclean : clean
	$(MAKE) -C libft/ fclean
	/bin/rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean