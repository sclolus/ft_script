/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 06:27:37 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/01 17:27:14 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCRIPT_H
# define FT_SCRIPT_H

# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <sys/termios.h>
# include <time.h>
# include <sys/time.h>
# include <sys/stat.h>

# include <stdio.h> // to remove

# define SCRIPT_FLAGS "adFkpqrt"
# define SCRIPT_FLAGS_GETOPT "adF:kpqrt:"
# define DFL_SCRIPT_FILE "typescript"
# define DFL_SCRIPT_FLUSH_TIME 30

typedef struct	s_bits16
{
	uint16_t	append : 1;
	uint16_t	no_sleep : 1;
	uint16_t	pipe : 1;
 	uint16_t	keylog : 1;
	uint16_t	play_back : 1;
	uint16_t	quiet : 1;
	uint16_t	timestamp : 1;
	uint16_t	flush_time : 1;
	uint16_t	bit9 : 1;
	uint16_t	bit10 : 1;
	uint16_t	bit11 : 1;
	uint16_t	bit12 : 1;
	uint16_t	bit13 : 1;
	uint16_t	bit14 : 1;
	uint16_t	bit15 : 1;
	uint16_t	bit16 : 1;
}				t_bits16;

typedef union	u_flags16
{
	t_bits16	bits;
	uint16_t	flags;
}				t_flags16;

typedef struct	s_script_info
{
	char		**command_argv;
	char		*file_script;
	time_t		flush_time;
	t_flags16	flags;
	uint8_t		pad[6];
}				t_script_info;

/*
** Parsing
*/

t_script_info	*ft_parse_args(int argc, char **argv, char **env);

/*
** GNU stdlib c
*/

int		ft_grantpt(int fd); // to be implemented
int		ft_tcgetattr(int fd, struct termios *t);
int		ft_tcsetattr(int fd, struct termios *t);

extern struct termios base_termios;
extern struct winsize base_winsize;

int		get_base_winsize(void);
int		set_winsize(int fd, struct winsize *winsize);

/*
** Master side
*/

void		ft_get_term_info(void);
int			set_master_termios(int master_fd);
int			open_typescript_file(const t_script_info *info);

NORETURN	master_routine(int master_fd, pid_t slave_pid, int typescript_fd, t_script_info *info);

# define SCRIPT_START_FILE "Script started on "
# define SCRIPT_END_FILE "Script done on "
# define SCRIPT_START_STDOUT "Script started, output file is "
# define SCRIPT_END_STDOUT "\nScript done, output file is "

void		print_script_start(int typescript_fd, t_script_info *info);
void		print_script_end(int typescript_fd, t_script_info *info);

/*
** Slave side
*/

# define SHELL_VAR "SHELL="
# define SCRIPT_VAR "SCRIPT="
# define BOURNE_SHELL_DEFAULT_PATH "/bin/sh"

pid_t	get_slave_fork(const char *slave_name, int master_fd);
void	exec_shell(char **env);

# define PTMX_FILENAME "/dev/ptmx"

/*
** Error handling
*/

# define SCRIPT_USAGE "usage: script [-adkpqr] [-t time] [file [command ...]]"

void			print_usage(void);
NORETURN		cleanup_exit(int exit_status, int typescript_fd
							, t_script_info *info);
void			reset_tty(void);
#endif
