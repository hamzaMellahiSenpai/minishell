/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 16:12:12 by marvin            #+#    #+#             */
/*   Updated: 2020/04/02 16:12:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

/*
  List of builtin commands, followed by their corresponding functions.
 */
t_string    *init_cmds()
{
    t_string    *cmds_str;

	cmds_str = sf_malloc(sizeof(char*) * 9);
    cmds_str[0] = "help";
    cmds_str[1] = "echo";
    cmds_str[2] = "pwd";
    cmds_str[3] = "exit";
    cmds_str[4] = "cd";
    cmds_str[5] = "env";
    cmds_str[6] = "unset";
    cmds_str[7] = "export";
    cmds_str[8] = "history";
    cmds_str[9] = 0;
    return (cmds_str);
}

t_string (*cmds(int i))(char **args)
{
    t_string    (*builtin_func[10]) (char **args);

    builtin_func[0] = &shell_help;
    builtin_func[1] = &shell_echo;
    builtin_func[2] = &shell_pwd;
    builtin_func[3] = &shell_exit;
    builtin_func[4] = &shell_cd;
    builtin_func[5] = &shell_env;
    builtin_func[6] = &shell_unset;
    builtin_func[7] = &shell_export;
    builtin_func[7] = &shell_history;
    builtin_func[8] = NULL;
    //builtin_func[4] = NULL;
    return (builtin_func[i]);
}