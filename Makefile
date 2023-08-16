NAME = minishell
SRCS = lexer.c utils.c splitter.c tokenizer.c main_lucia_y_el_uraño.c utils2.c env_list.c
CFLAGS = -Wall -Wextra -Werror -I /Users/$(USER)/.brew/opt/readline/include #-fsanitize=address
LDFLAGS = -L /Users/$(USER)/.brew/opt/readline/lib -lreadline #-fsanitize=address
RM = /bin/rm -rf
OBJS = $(SRCS:%.c=objs/%.o)
OBJS += libft/libft.a

$(NAME): objs $(OBJS)
	cc $(OBJS) $(LDFLAGS) -o $(NAME)
all: $(NAME)
clean:
	$(RM) objs
	make fclean -C libft
fclean: clean
	$(RM) $(NAME)
re: fclean all

libft/libft.a: 
	make -C libft
objs:
	mkdir -p objs
objs/%.o: %.c
	cc $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
