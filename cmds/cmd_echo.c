/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 02:07:37 by marvin            #+#    #+#             */
/*   Updated: 2020/04/02 02:07:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_string get_value(t_string str){return str;}
t_string     shell_echo(t_string *args)
{
  int i;
  int j;
  int flag;
  int arg_len;

  flag = 0;
  i = 0;
  t_string spec_charcs = "\"\\n";
  //printf("%s\n", spec_charcs);
  while(args[++i])
  {
    j = -1;
    if (i != 1)
      shell.output = join(shell.output," ");
    arg_len = ft_strlen(args[i]);
    while(args[i][++j])
    {
      flag = 1;
      if (args[i][j] == '$')
      {
        j++;
        int end = j;
        while(!ft_strchr("$ ", args[i][end]))
          end++;
        if (end != j)
        {
          shell.output = join(shell.output, get_value(substr(args[i], j, end + 1)));
          j = end + 1;
        }else if (args[i][j] == '$')
        {
          shell.output = join(shell.output, "10996");
          j++;
        }
        continue;
      }
     // else if (args[i][])
      else if((args[i][j] == '\\' && ft_strchr(spec_charcs, args[i][j + 1]) && (j + 2 != arg_len))
      || (args[i][j] == '"' && j != 0 && !ft_strchr(spec_charcs, args[i][j - 1])))
        flag = 0;
      if (flag)
      {
        //shell.output = join(shell.output, &args[i][j]);
      }
    }
  }
  return "1";
}