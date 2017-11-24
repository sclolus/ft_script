/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_base_winsize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 07:41:59 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/21 07:51:30 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

inline int	get_base_winsize(void)
{
	return (ioctl(STDIN_FILENO, TIOCGWINSZ, &base_winsize));
}
