/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 23:26:13 by marvin            #+#    #+#             */
/*   Updated: 2020/04/06 23:26:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_string     shell_unset(t_string *args)
{
    int         index;
    int         j;
    int         i;
    t_string    key;
    int         flag;

    j = 0;
    while (args[++j])
    {
        index = vector_find(&shell.env, args[j]);
        vector_delete(&shell.env, index);
    }
    return "1";
}