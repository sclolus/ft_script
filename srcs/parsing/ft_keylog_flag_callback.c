/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keylog_flag_callback.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:05:30 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/23 20:06:07 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_args.h"

int32_t	ft_keylog_flag_callback(t_script_info* script_info)
{
	script_info->flags.bits.keylog = 1;
	return (0);
}
