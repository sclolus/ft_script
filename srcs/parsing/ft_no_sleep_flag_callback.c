/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_sleep_flag_callback.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:34:28 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/23 20:04:10 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_args.h"

int32_t	ft_no_sleep_flag_callback(t_script_info* script_info)
{
	script_info->flags.bits.no_sleep = 1;
	return (0);
}
