/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grantpt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 08:53:25 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/20 09:33:57 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int	ft_grantpt(int fd)
{
	char	*slave_name;

	if (!(slave_name = ptsname(fd)))
	{
		ft_error(1, (char*[]){"Failed to retrieve slave pt name"}, 0);
		return (-1);
	}
	if (-1 == chown((const char*)slave_name, getuid(), (gid_t)-1))
	{
		ft_error(1, (char*[]){"Failed to set slave pt name modes"}, 0);
		return (-1);
	}
	return (0);
}
