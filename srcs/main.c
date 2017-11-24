/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 06:27:19 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/24 03:30:42 by sclolus          ###   ########.fr       */
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
	while (i < 8)
	{
		printf("%c: %u\n", (SCRIPT_FLAGS[i]), !!(info->flags.flags & (1U << i)));
		i++;
	}
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
	print_script_info(script_info);
	if (-1 == (master_fd = open(PTMX_FILENAME, O_RDWR | O_NOCTTY)))
		_exit(EXIT_FAILURE);
	printf("master_fd : %d\n", master_fd);
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
	printf("slave_name: %s\n", slave_name);

	if (-1 == (pid = get_slave_fork(slave_name, master_fd)))
		_exit(EXIT_FAILURE);
	else if (pid)
	{
		typescript_fd = open_typescript_file(script_info);
		set_master_termios(master_fd);
		master_routine(master_fd, pid, typescript_fd); // please set a serious open
	}
	else
		exec_shell(env);
}
