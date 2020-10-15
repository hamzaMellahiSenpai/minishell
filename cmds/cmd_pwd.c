/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 02:06:28 by marvin            #+#    #+#             */
/*   Updated: 2020/04/02 02:06:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_string    shell_pwd()
{
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		handle_error(GETCWD_FAIL, FAIL);
	shell.output = join(shell.output, join(cwd, "\n"));
	return (cwd);
}
