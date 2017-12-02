/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 06:27:19 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/02 00:36:25 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"
#include <stdio.h> //

/* Todo list
** ft_exit
*/

struct termios	base_termios;
struct winsize	base_winsize;

static void	print_script_info(t_script_info *info)
{
	uint32_t	i;
	printf("filescript: %s\nflush_time: %ld\n", info->file_script, info->flush_time);

	i = 0;
	/* while (i < 8) */
	/* { */
	/* 	printf("%c: %u\n", (SCRIPT_FLAGS[i]), !!(info->flags.flags & (1U << i))); */
	/* 	i++; */
	/* } */
	printf("command: ");

	while (info->command_argv && info->command_argv[i])
	{
		printf("%s ", info->command_argv[i]);
		i++;
	}
	if (!info->command_argv)
		printf("(null)");
	printf("\n");
}

int	main(int argc, char **argv, char **env)
{
	t_script_info	*script_info;
	char			*slave_name;
	int				master_fd;
	int				typescript_fd;
	pid_t			pid;

	ft_get_term_info();
	script_info = ft_parse_args(argc, argv, env);
	if (-1 == (master_fd = open(PTMX_FILENAME, O_RDWR | O_NOCTTY)))
		_exit(EXIT_FAILURE);
	if (grantpt(master_fd) || unlockpt(master_fd))
	{
		perror(NULL); // to remove
		_exit(EXIT_FAILURE);
	}
	if (!(slave_name = ptsname(master_fd)))
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	print_script_info(script_info);
	if (-1 == (pid = get_slave_fork(slave_name, master_fd)))
		_exit(EXIT_FAILURE);
	else if (pid)
	{
		typescript_fd = open_typescript_file(script_info);
		print_script_start(typescript_fd, script_info);
		set_master_termios(master_fd);
		master_routine(master_fd, pid, typescript_fd, script_info);
	}
	else
		exec_shell(script_info, env);
}
