/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 09:32:26 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/24 03:32:20 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

/*
** Routine executed by the parent i.e the master side of the pty
** master_fd is the fd of the master-side pty
** slave_pid is the pid of the slave fork
** typescript_fd is the fd of the opened file use to record session
*/

NORETURN	master_routine(int master_fd, pid_t slave_pid, int typescript_fd)
{
	static char	buffer[256];
	ssize_t		len;
	fd_set		in_fds;
	int			ndfs;

	ndfs = (master_fd > STDIN_FILENO ? master_fd : STDIN_FILENO) + 1;
	(void)slave_pid;
	while (42)
	{
		FD_ZERO(&in_fds);
		FD_SET(master_fd, &in_fds);
		FD_SET(STDIN_FILENO, &in_fds);
		if (-1 == select(master_fd + 1, &in_fds, NULL, NULL, NULL))
		{
			ft_error(1, (char*[]){"select() failed"}, 0);
			cleanup_exit(EXIT_FAILURE);
		}
		if (FD_ISSET(STDIN_FILENO, &in_fds))
		{
			if (0 >= (len = read(STDIN_FILENO, buffer, 4096)))
				cleanup_exit(EXIT_SUCCESS);
			if (-1 == write(master_fd, buffer, (uint64_t)len))
				ft_error_exit(1, (char*[]){"Partial write failure"}, EXIT_FAILURE);
		}
		if (FD_ISSET(master_fd, &in_fds))
		{
			if (0 >= (len = read(master_fd, buffer, 256)))
				cleanup_exit(EXIT_SUCCESS);
			if (-1 == write(typescript_fd, buffer, (uint64_t)len)
				|| -1 == write(STDOUT_FILENO, buffer, (uint64_t)len))
				ft_error_exit(1, (char*[]){"Partial write failure"}, EXIT_FAILURE);
		}
	}
}
