/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quiet_flag_callback.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:07:34 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/23 20:08:05 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_args.h"

int32_t	ft_quiet_flag_callback(t_script_info *script_info)
{
	script_info->flags.bits.quiet = 1;
	return (0);
}
