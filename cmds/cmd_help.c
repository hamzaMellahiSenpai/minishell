/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 02:10:47 by marvin            #+#    #+#             */
/*   Updated: 2020/04/02 02:10:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

/**
   @brief Builtin command: print help.
   @param args List of args.  Not examined.
   @return Always returns 1, to continue executing.
 */
t_string shell_help(char **args)
{
  int i;

  shell.output = join(shell.output, "Kirwa shell\n Type program names and arguments, and hit enter.\n The following are built in:");
  i = -1;
  while (++i < shell.cmds_count)
  {
    shell.output = join(shell.output, "\n>>> ");
    shell.output = join(shell.output, shell.cmds_str[i]);
  }
  ft_putstr("Use the man command for information on other programs.\n");
  return "1";
}