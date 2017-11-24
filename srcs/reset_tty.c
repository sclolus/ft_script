/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_tty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:26:04 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/21 10:26:43 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_script.h"

__attribute__((destructor)) void reset_tty(void)
{
	if (-1 == ft_tcsetattr(STDIN_FILENO, &base_termios))
	{
		ft_error(1, (char*[]){"Failed to reset default tty attributes"}, 0);
		_exit(EXIT_FAILURE);
	}
}
