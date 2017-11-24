/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_typescript_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 03:25:13 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/24 03:30:02 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

inline int	open_typescript_file(const t_script_info *info)
{
	int	fd;

	fd = open(info->file_script, O_WRONLY | O_CREAT
			  | (info->flags.bits.append ? O_APPEND : O_TRUNC)
			, S_IRUSR | S_IWUSR | S_IWGRP | S_IWOTH);
	if (fd == -1)
	{
		ft_error(1, (char*[]){"Could not open typescript file"}, 0); // change this to check which error
		_exit(EXIT_FAILURE);
	}
	return (fd);
}
