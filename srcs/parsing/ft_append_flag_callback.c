/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_flag_callback.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:32:03 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/24 00:24:29 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_args.h"

int32_t	ft_append_flag_callback(t_script_info* script_info)
{
	script_info->flags.bits.append = 1;
	return (0);
}
