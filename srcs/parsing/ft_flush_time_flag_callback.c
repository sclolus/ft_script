/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flush_time_flag_callback.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:09:15 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/24 00:52:51 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_args.h"

int32_t	ft_flush_time_flag_callback(t_script_info* script_info)
{
	script_info->flags.bits.flush_time = 1;
	script_info->flush_time = ft_atol(g_optarg);
	return (0);
}
