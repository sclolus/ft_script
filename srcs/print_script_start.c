/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_script_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 09:13:14 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/24 09:47:16 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

inline void	print_script_start(int typescript_fd, t_script_info *info)
{
	struct timeval	time;
	char			*time_str;

	gettimeofday(&time, NULL);
	if (!(time_str = ctime(&time.tv_sec)))
	{
		ft_error(1, (char*[]){"Failed to gettimeofday()"}, 0);
		_exit(EXIT_FAILURE);
	}
	ft_putstr_fd(SCRIPT_START_FILE, typescript_fd);
	ft_putstr_fd(time_str, typescript_fd);
	ft_putstr(SCRIPT_START_STDOUT);
	ft_putstr(info->file_script);
	ft_putchar('\n');
}
