/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:23:34 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/21 10:25:21 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

/*
** Simply call the destructors, i.e, reset the terminal to original attributes
** and _exit with exit_status as paramater
*/

NORETURN	cleanup_exit(int exit_status)
{
	reset_tty();
	_exit(exit_status);
}
