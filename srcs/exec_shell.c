/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 08:05:15 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/21 08:45:20 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

/*
** Paramater should be const qualified however Weverything is bitching me
*/

static char *find_shell_path(char **env)
{
	uint64_t	i;

	i = 0;
	while (env[i])
	{
		if (ft_strnequ(env[i], SHELL_VAR, sizeof(SHELL_VAR) - 1))
			return (env[i] + sizeof(SHELL_VAR) - 1);
		i++;
	}
	return (NULL);
}

void	exec_shell(char **env)
{
	char	*path;

	if (!(path = find_shell_path(env)))
		path = BOURNE_SHELL_DEFAULT_PATH;
//	env = add_script_to_env(env);
	if (-1 == (execve(path, (char*[]){path, NULL}, env)))
	{
		ft_error(1, (char*[]){"execve() failed to exec forked shell"}, 0);
		exit(EXIT_FAILURE);
	}
}
