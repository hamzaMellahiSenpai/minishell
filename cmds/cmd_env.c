/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 19:23:36 by marvin            #+#    #+#             */
/*   Updated: 2020/04/04 19:23:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_string     shell_env(t_string *args)
{
  int i;

  i = -1;
  #if DEBUG_MODE
    printf("%d\n", shell.env.size);
  #endif
  while(++i < shell.env.size - 1)
  {
    shell.output = join(shell.output, vector_get(&shell.env, i));
    shell.output = join(shell.output, "\n");
  }
  return "1";
}