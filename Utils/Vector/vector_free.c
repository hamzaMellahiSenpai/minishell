/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 00:24:14 by marvin            #+#    #+#             */
/*   Updated: 2020/04/09 00:24:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void    vector_free(t_vector *v)
{
    // int i;

    // i = -1;
    // while(v->items[++i])
    // {
    //     void *cur = v->items[i];
    //     v->items[i] = v->items[i+1];
    //     free(cur);
    // }
    printf("\n\n\nh\n\n");
    free(v->items);
}