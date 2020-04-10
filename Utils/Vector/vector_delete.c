/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 18:05:39 by marvin            #+#    #+#             */
/*   Updated: 2020/04/04 18:05:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void vector_delete(t_vector *this, int index)
{
    if (index < 0 || index >= this->size)
        return;

    this->items[index] = NULL;

    for (int i = index; i < this->size - 1; i++) {
        this->items[i] = this->items[i + 1];
        this->items[i + 1] = NULL;
    }

    this->size--;

    if (this->size > 0 && this->size == this->capacity / 4)
        vector_resize(this, this->capacity / 2);
}