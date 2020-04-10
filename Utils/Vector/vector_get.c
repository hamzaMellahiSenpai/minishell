/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 18:02:40 by marvin            #+#    #+#             */
/*   Updated: 2020/04/04 18:02:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void    *vector_get(t_vector *this, int index)
{
    if (index >= 0 && index < this->size)
        return this->items[index];
    return NULL;
}