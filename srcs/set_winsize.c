/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_winsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 07:52:52 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/21 07:54:08 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

inline int	set_winsize(int fd, struct winsize *winsize)
{
	return (ioctl(fd, TIOCSWINSZ, winsize));
}
