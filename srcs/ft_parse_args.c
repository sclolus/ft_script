/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:59:11 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/24 03:27:07 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"
#include "parse_args.h"

#include <stdio.h>

t_script_info	*ft_parse_args(int argc, char **argv, char **env)
{
	static t_script_info			script_info;
	const static t_parse_callback	callbacks[] = {
		{&ft_append_flag_callback, SCRIPT_FLAGS[0], {0}},
		{&ft_no_sleep_flag_callback, SCRIPT_FLAGS[1], {0}},
		{&ft_pipe_flag_callback, SCRIPT_FLAGS[2], {0}},
		{&ft_keylog_flag_callback, SCRIPT_FLAGS[3], {0}},
		{&ft_play_back_flag_callback, SCRIPT_FLAGS[4], {0}},
		{&ft_quiet_flag_callback, SCRIPT_FLAGS[5], {0}},
		{&ft_timestamp_flag_callback, SCRIPT_FLAGS[6], {0}},
		{&ft_flush_time_flag_callback, SCRIPT_FLAGS[7], {0}},
	};
	char							retrieved_opt;

	script_info.file_script = DFL_SCRIPT_FILE;
	while ((retrieved_opt = (char)ft_getopt(argc, argv, SCRIPT_FLAGS_GETOPT)) != -1)
	{
		if (retrieved_opt == GETOPT_ERR_CHAR)
		{
			print_usage();
			_exit(EXIT_FAILURE);
		}
//		printf("g_optind: %d, last_char: %c\n", g_optind, (char)retrieved_opt);
		callbacks[(int)(ft_strchr(SCRIPT_FLAGS, retrieved_opt) - SCRIPT_FLAGS)].callback(&script_info);
	}
	(void)env;
	return (&script_info);
}
