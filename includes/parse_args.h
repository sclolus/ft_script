/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:06:42 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/24 00:24:00 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ARGS_H
# define PARSE_ARGS_H

# include "ft_script.h"

typedef int32_t	(*t_f_callback)(t_script_info*);

typedef struct	s_parse_callback
{
	t_f_callback	callback;
	char			id;
	uint8_t			pad[7];
}				t_parse_callback;

/*
** Callbacks
*/

int32_t	ft_append_flag_callback(t_script_info *script_info);
int32_t	ft_no_sleep_flag_callback(t_script_info *script_info);
int32_t	ft_pipe_flag_callback(t_script_info *script_info);
int32_t	ft_keylog_flag_callback(t_script_info *script_info);
int32_t	ft_play_back_flag_callback(t_script_info *script_info);
int32_t	ft_quiet_flag_callback(t_script_info *script_info);
int32_t	ft_timestamp_flag_callback(t_script_info *script_info);
int32_t	ft_flush_time_flag_callback(t_script_info *script_info);

#endif
