/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 18:45:20 by marvin            #+#    #+#             */
/*   Updated: 2020/04/04 18:45:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void vector_push_back(t_vector *this, void *item)
{
    if (this->capacity == this->size)
        vector_resize(this, this->capacity * 2);
    this->items[this->size++] = item;
}