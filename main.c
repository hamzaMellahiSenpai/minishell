/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 02:04:04 by marvin            #+#    #+#             */
/*   Updated: 2020/04/02 02:04:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

void  init_env(t_string *env)
{
  int i;

  new_vector(&shell.env);
  i = -1;
  while(env[++i])
  {
    vector_push_back(&shell.env, env[i]);
  //    printf("%s\n", (t_string)vector_get(&shell.env, i));
  }
  vector_push_back(&shell.env, 0);
}

void  init_shell(t_string *env)
{
  new_vector(&shell.adresses);
  //vector_push_back(&shell.adresses, &shell.adresses);
  shell.errors = init_errors();
  shell.cmds_str  = init_cmds();
  shell.cmds_count = tablen((void**)shell.cmds_str);
  shell.curr_dir  = shell_pwd();
  shell.name = "kiro";
  shell.cmds = &cmds;
  shell.max_output_len = 0;
  // (shell.env).new = new_vector;
  // (shell.env).push_back = vector_push_back;
  // (shell.env).set = vector_set;
  // (shell.env).get = vector_get;
  // (shell.env).delete = vector_delete;
  init_env(env);
}
#include "leak/malloc.h"

int main(int argc, char **argv, char **env)
{
  // Load config files, if any.
  init_shell(env);
  signal(CTRL_C, event_handler);
  //textcolor(15);
  ft_putstr("Welcome to kiro, the best shell ever\n");
  // Run command loop.
  shell_loop();
  free_all();
  leakcheck();
  return EXIT_SUCCESS;
}
