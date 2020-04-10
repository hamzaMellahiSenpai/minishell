/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 14:37:07 by marvin            #+#    #+#             */
/*   Updated: 2020/04/02 14:37:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMDS_H
#define CMDS_H
/*
  Function Declarations for builtin shell commands:
 */
void		shell_loop(void);
t_string			shell_cd(char **args);
t_string         shell_help(char **args);
t_string			shell_exit(char **args);
t_string         shell_clear();
t_string         shell_pwd();
t_string     shell_echo();
t_string     shell_env(t_string *args);
t_string     shell_export(t_string *args);
t_string     shell_unset(t_string *args);
t_string    shell_history(char **args);
t_string    *init_cmds();
t_string (*cmds(int i))(char **args);
#endif