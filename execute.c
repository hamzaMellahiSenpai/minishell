/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 02:16:03 by marvin            #+#    #+#             */
/*   Updated: 2020/04/02 02:16:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

/**
   @brief Execute shell built-in or launch program.
   @param args Null terminated list of arguments.
   @return 1 if the shell should continue running, 0 if it should terminate
 */

t_string execute(char **args)
{
  int i;

  if (args[0] == NULL)
    return "1";
  i = -1;
  while (++i < shell.cmds_count)
    if (ft_strcmp(args[0], shell.cmds_str[i]) == 0)
      return ((*shell.cmds)(i))(args);
  shell.output = join(shell.output,"\n");
  return shell_launch(args);
}
