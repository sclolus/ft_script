/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_slave_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:07:27 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/21 07:55:09 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

static void	set_pty_fds(int slave_fd)
{
	if (dup2(slave_fd, STDIN_FILENO) != STDIN_FILENO)
	{
		ft_error(1, (char*[]){"Failed to set STDIN_FILENO"}, 0);
		_exit(EXIT_FAILURE);
	}
	if (dup2(slave_fd, STDOUT_FILENO) != STDOUT_FILENO)
	{
		ft_error(1, (char*[]){"Failed to set STDOUT_FILENO"}, 0);
		_exit(EXIT_FAILURE);
	}
	if (dup2(slave_fd, STDERR_FILENO) != STDERR_FILENO)
	{
		ft_error(1, (char*[]){"Failed to set STDERR_FILENO"}, 0);
		_exit(EXIT_FAILURE);
	}
	if (slave_fd > STDERR_FILENO)
		close(slave_fd);
}

pid_t	get_slave_fork(const char *slave_name, int master_fd)
{
	pid_t	pid;
	int		slave_fd;

	if (-1 == (pid = fork()))
	{
		ft_error(1, (char*[]){"Failed to fork()"}, 0);
		return (pid);
	}
	else if (pid)
		return (pid);
	else
	{
		close(master_fd);
		if (setsid() == -1)
		{
			ft_error(1, (char*[]){"Failed setsid()"}, 0);
			_exit(EXIT_FAILURE);
		}
		if (-1 == (slave_fd = open(slave_name, O_RDWR)))
		{
			ft_error(1, (char*[]){"Failed to open slave device"}, 0);
			_exit(EXIT_FAILURE);
		}

#ifdef TIOCSCTTY
		if (ioctl(slave_fd, TIOCSCTTY, 0) == -1)
		{
			ft_error(1, (char*[]){"Failed to set controlling terminal"}, 0);
			_exit(EXIT_FAILURE);
		}
#endif
		if (-1 == ft_tcsetattr(slave_fd, &base_termios))
		{
			ft_error(1, (char*[]){"Failed to set slave attributes"}, 0);
			_exit(EXIT_FAILURE);
		}
		if (-1 == set_winsize(slave_fd, &base_winsize))
		{
			ft_error(1, (char*[]){"Failed to set slave winsize"}, 0);
			_exit(EXIT_FAILURE);
		}
		set_pty_fds(slave_fd);
		return (0);
	}
}
