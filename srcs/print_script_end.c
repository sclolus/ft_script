/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_script_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 09:34:50 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/24 10:51:34 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

inline void	print_script_end(int typescript_fd, t_script_info *info)
{
	struct timeval	time;
	char			*time_str;

	gettimeofday(&time, NULL);
	if (!(time_str = ctime(&time.tv_sec)))
	{
		ft_error(1, (char*[]){"Failed to gettimeofday()"}, 0);
		_exit(EXIT_FAILURE);
	}
	if (!info->flags.bits.quiet)
	{
		ft_putchar_fd('\n', typescript_fd);
		ft_putstr_fd(SCRIPT_END_FILE, typescript_fd);
		ft_putstr_fd(time_str, typescript_fd);
		ft_putstr(SCRIPT_END_STDOUT);
		ft_putstr(info->file_script);
		ft_putchar('\n');
	}
}
