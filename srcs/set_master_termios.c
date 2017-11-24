/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_master_termios.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 08:49:18 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/21 10:33:14 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

inline int	set_master_termios(int master_fd __attribute__((unused)))
{
	struct termios master_termios;

	master_termios = base_termios;

	master_termios.c_lflag &= ~(uint64_t)(ICANON | ISIG | IEXTEN | ECHO);
	master_termios.c_oflag &= ~(uint64_t)OPOST;
	master_termios.c_iflag &= ~(uint64_t)(ICRNL | IGNBRK | BRKINT |
							IGNCR | INPCK | INLCR | ISTRIP | IXON | PARMRK);
	master_termios.c_cc[VMIN] = 1;
	master_termios.c_cc[VTIME] = 0;
	if (-1 == ft_tcsetattr(STDIN_FILENO, &master_termios))
	{
		ft_error(1, (char*[]){"Failed to set master termios attributes"}, 0);
		_exit(EXIT_FAILURE);
	}
	return (0);
}
