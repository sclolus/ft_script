/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:23:34 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/01 22:32:54 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

/*
** Simply call the destructors, i.e, reset the terminal to original attributes
** and _exit with exit_status as paramater
*/

NORETURN	cleanup_exit(int exit_status, int typescript_fd
						, t_script_info *info)
{
	reset_tty();
	ft_static_put_fd(NULL, 0, STATIC_PUT_FLUSH, typescript_fd);
	print_script_end(typescript_fd, info);
	_exit(exit_status);
}
