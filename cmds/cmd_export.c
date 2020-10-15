/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 23:24:38 by marvin            #+#    #+#             */
/*   Updated: 2020/04/06 23:24:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_string     shell_export(t_string *args)
{
    int         j;
    t_string    *arg;
    t_string    key;
    int         index;
    j = 0;
        printf("%s\n", args[j]);
    while (args[++j])
    {
        arg = split(args[j], '=');
        if (!arg[1])
        {
            handle_error(SYNTAX_ERROR, FAIL);
            continue;
        }
        key = arg[0];
        index = vector_find(&shell.env, key);
        printf("%d\n", index);
        printf("%s\n", ((t_string)vector_get(&shell.env, index)));
        if (!vector_get(&shell.env , index))
        {
            vector_push_back(&shell.env, args[j]);
            //index = shell.env.size - 2;
        }
        else
            vector_set(&shell.env, index, args[j]);
        printf("%d\n", index);
        printf("%s\n", ((t_string)vector_get(&shell.env, index)));
    }
    return "1";
}