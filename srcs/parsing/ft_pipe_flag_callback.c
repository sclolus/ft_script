/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_flag_callback.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:36:11 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/24 00:39:44 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_args.h"

int32_t	ft_pipe_flag_callback(t_script_info *script_info)
{
	script_info->flags.bits.pipe = 1;
	script_info->file_script = g_optarg;
	return (0);
}
