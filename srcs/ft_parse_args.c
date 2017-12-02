/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:59:11 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/02 00:32:18 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"
#include "parse_args.h"

static void		post_opt_parsing(int argc, char **argv, char **env
								, t_script_info *info)
{
	(void)env;
	if (argc > g_optind)
	{
		if (g_optopt != 'F')
			info->file_script = argv[g_optind++];
		if (argv[g_optind])
			info->command_argv = argv + g_optind;
	}
}

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

	(void)env;
	script_info.file_script = DFL_SCRIPT_FILE;
	script_info.flush_time = DFL_SCRIPT_FLUSH_TIME;
	while ((retrieved_opt = (char)ft_getopt(argc, argv, SCRIPT_FLAGS_GETOPT)) != -1)
	{
		if (retrieved_opt == GETOPT_ERR_CHAR)
		{
			print_usage();
			_exit(EXIT_FAILURE);
		}
		if (callbacks[(int)(ft_strchr(SCRIPT_FLAGS, retrieved_opt)
							- SCRIPT_FLAGS)].callback(&script_info))
			break;
	}
	post_opt_parsing(argc, argv, env, &script_info);
	return (&script_info);
}
