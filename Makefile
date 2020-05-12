SRC = ft_printf.c walking_function.c factory_structs.c checkers.c put_di.c final_reading.c put_percent.c count_chars.c filtro_valist.c put_char.c put_string.c ft_unsigneditoa.c put_uint.c change_base16.c put_p.c checkers2.c
HEADER = libftprintf.h
NAME = libftprintf.a
OBJS = $(SRC:.c=.o)


all:	$(NAME)

$(NAME):
	@(cd libft ; make ; cp libft.a ../libftprintf.a)
	@gcc -I -Wall -Wextra -Werror $(HEADER) -c $(SRC)
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@(cd libft ; make clean)

fclean:	clean
	@rm -f $(NAME)
	@(cd libft ; make fclean)

re:	fclean all
