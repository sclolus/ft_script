/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_back_flag_callback.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:06:32 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/24 00:27:27 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_args.h"

int32_t	ft_play_back_flag_callback(t_script_info *script_info)
{
	script_info->flags.bits.play_back = 1;
	return (0);
}
