NAME= ft_script
SRC= srcs/main.c \
	srcs/ft_grantpt.c \
	srcs/get_slave_fork.c \
	srcs/ft_tcgetattr.c \
	srcs/ft_tcsetattr.c \
	srcs/get_base_winsize.c \
	srcs/set_winsize.c \
	srcs/exec_shell.c \
	srcs/set_master_termios.c \
	srcs/master_routine.c \
	srcs/cleanup_exit.c \
	srcs/reset_tty.c \
	srcs/ft_get_term_info.c \
	srcs/print_usage.c \
	srcs/ft_parse_args.c \
	srcs/parsing/ft_append_flag_callback.c \
	srcs/parsing/ft_flush_time_flag_callback.c \
	srcs/parsing/ft_keylog_flag_callback.c \
	srcs/parsing/ft_no_sleep_flag_callback.c \
	srcs/parsing/ft_pipe_flag_callback.c \
	srcs/parsing/ft_play_back_flag_callback.c \
	srcs/parsing/ft_quiet_flag_callback.c \
	srcs/parsing/ft_timestamp_flag_callback.c \
	srcs/open_typescript_file.c

OBJ= $(SRC:.c=.o)
HDR_PATH= ./libft/includes/
CC= gcc
CC_FLAGS= -Ofast -v -Weverything -Wall -Werror -Wextra  -g3 -fsanitize=address -fsanitize-blacklist=my_ignores.txt #-Werror
#VPATH=./srcs:./obj:./includes/

all: submodule $(NAME)

submodule:
	@make -C libft/

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $^ -L./libft -lft -o $(NAME)
%.o : %.c
	$(CC) $(CC_FLAGS) $< -c -I$(HDR_PATH) -I./includes -o $@

clean:
	rm -f $(OBJ)
	make -C libft/ clean
fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
