/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 01:07:38 by marvin            #+#    #+#             */
/*   Updated: 2020/04/07 01:07:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int     vector_find(t_vector *v, t_string value)
{
    int         i;
    t_string    key;

    i = -1;
    while (++i < shell.env.size - 1)
    {
        key = split(vector_get(v, i), '=')[0];
        if (ft_strcmp(key, value) == 0)
            return (i);
    }
    printf("%s | %s\n", key, value);
    return (-1);
}