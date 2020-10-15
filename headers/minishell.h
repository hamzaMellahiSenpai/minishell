/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers/minishell.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 00:29:02 by marvin            #+#    #+#             */
/*   Updated: 2020/03/31 00:29:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "../leak/malloc.h"
#include <stdio.h>
#include <limits.h>
#include <signal.h>

#define BUFFER_SIZE 1024
#define FAIL 0
#define UNCOMPLETED 1
#define STDIN 0
#define DEBUG_MODE 1
#define CMDS_COUNT 10
typedef char* t_string;


/// Includes
#include "utils.h"
#include "cmds.h"
#include "vector.h"

// events
void  event_handler(int sig);
void    handle_ctrl_c(int sig);


enum							e_errors
{
	Allocation_Failed,
    GETCWD_FAIL,
    INDEFINED_CMD,
    SYNTAX_ERROR
};

enum                            events
{
    CTRL_AS,
    CTRL_D,
    CTRL_C
};

char cwd[PATH_MAX];
typedef struct s_shell
{
    t_string    name;
    t_string    curr_dir;
    t_vector    adresses;
    t_string    output;
    int         max_output_len;
    int         cmds_count;
    char        **cmds_str;
    char        **errors;
    t_string (*(*cmds)(int i))(char **args);
    t_vector    env;
    t_vector    history;
}              t_shell;

t_shell         shell;

//char *cmds_str[5];

//int (*builtin_func[5]) (char **);


//int shell_num_builtins();
t_string execute(char **args);
t_string    shell_launch(char **args);

#endif