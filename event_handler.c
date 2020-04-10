/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 02:04:42 by marvin            #+#    #+#             */
/*   Updated: 2020/04/01 02:04:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

void  event_handler(int sig)
{
     char  c;

    if (sig == CTRL_C)
    {
        ft_putstr("\nTerminated by Ctrl-C\n");
        exit(UNCOMPLETED);
    }else if (sig == CTRL_D)
    {
        ft_putstr("\nTerminated by Ctrl-D\n");
        exit(UNCOMPLETED);
    }else if (sig == CTRL_AS)
    {
        //x = SIGTSTP
    }
}