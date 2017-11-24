/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timestamp_flag_callback.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:08:26 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/23 20:09:03 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_args.h"

int32_t	ft_timestamp_flag_callback(t_script_info* script_info)
{
	script_info->flags.bits.timestamp = 1;
	script_info->flags.bits.keylog = 1; // probably
	return (0);
}
