/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_term_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:08:28 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/23 12:09:27 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

inline void	ft_get_term_info(void)
{
	if (-1 == (tcgetattr(STDIN_FILENO, &base_termios)))
	{
		ft_error(1, (char*[]){"Stdin is not a terminal"}, 0);
		_exit(EXIT_FAILURE);
	}
	if (-1 == get_base_winsize())
	{
		ft_error(1, (char*[]){"Failed to get base winsize"}, 0);
		_exit(EXIT_FAILURE);
	}
}
