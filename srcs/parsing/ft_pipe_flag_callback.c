/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_flag_callback.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:36:11 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/02 00:07:14 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_args.h"

int32_t	ft_pipe_flag_callback(t_script_info *script_info)
{
	script_info->flags.bits.pipe = 1;
	script_info->flush_time = 0;
	script_info->file_script = g_optarg;
	return (1);
}
