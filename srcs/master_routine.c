/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 09:32:26 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/01 22:41:46 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

/*
** Subroutine that checks time and returns true if the buffer
** must be flushed on disk
*/

static uint32_t	time_scheduler(t_script_info *info)
{
	static struct timeval	oldtime;
	static struct timeval	newtime;

	gettimeofday(&newtime, NULL);
	if (newtime.tv_sec - oldtime.tv_sec >= info->flush_time)
	{
		oldtime = newtime;
		return (1);
	}
	return (0);
}

static void	master_stdin_read_routine(t_script_info *info, int typescript_fd, int master_fd)
{
	static char	read_buffer[4096];
	ssize_t		len;

	if (0 >= (len = read(STDIN_FILENO, read_buffer, 4096)))
		cleanup_exit(EXIT_SUCCESS, typescript_fd, info);
	if (-1 == write(master_fd, read_buffer, (uint64_t)len))
		ft_error_exit(1, (char*[]){"Partial write failure"}, EXIT_FAILURE);
	if (info->flags.bits.keylog)
		ft_static_put_fd(read_buffer, (uint32_t)len, 0, typescript_fd);
}

static void	master_typescript_write_routine(t_script_info *info, int typescript_fd, int master_fd)
{
	static char	read_buffer[4096];
	ssize_t		len;

	if (0 >= (len = read(master_fd, read_buffer, 4096)))
		cleanup_exit(EXIT_SUCCESS, typescript_fd, info);
	ft_static_put_fd(read_buffer, (uint32_t)len, 0, typescript_fd);
	if (-1 == write(STDOUT_FILENO, read_buffer, (uint64_t)len))
		ft_error_exit(1, (char*[]){"Partial write failure"}, EXIT_FAILURE);
}

/*
** Routine executed by the parent i.e the master side of the pty
** master_fd is the fd of the master-side pty
** slave_pid is the pid of the slave fork
** typescript_fd is the fd of the opened file use to record session
*/

NORETURN	master_routine(int master_fd, pid_t slave_pid, int typescript_fd, t_script_info *info)
{
	fd_set			in_fds;
	int				ndfs;

	ndfs = (master_fd > STDIN_FILENO ? master_fd : STDIN_FILENO) + 1;
	(void)slave_pid;
	while (42)
	{
		FD_ZERO(&in_fds);
		FD_SET(master_fd, &in_fds);
		FD_SET(STDIN_FILENO, &in_fds);
		if (-1 == select(master_fd + 1, &in_fds, NULL, NULL, &(struct timeval){0, 200}))
		{
			ft_error(1, (char*[]){"select() failed"}, 0);
			cleanup_exit(EXIT_FAILURE, typescript_fd, info);
		}
		if (FD_ISSET(STDIN_FILENO, &in_fds))
			master_stdin_read_routine(info, typescript_fd, master_fd);
		if (FD_ISSET(master_fd, &in_fds))
			master_typescript_write_routine(info, typescript_fd, master_fd);
		if (time_scheduler(info))
			ft_static_put_fd(NULL, 0, STATIC_PUT_FLUSH, typescript_fd);
	}
}
