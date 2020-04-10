/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 16:08:32 by marvin            #+#    #+#             */
/*   Updated: 2020/04/03 16:08:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void    new_vector(t_vector *this)
{
	static int i= 0;
	this->size = 0;
	this->capacity = VECTOR_INIT_CAPACITY;
	if (i == 0)
	{
		this->items = malloc(sizeof(void *) * this->capacity);
		i++;
	}else
		this->items = sf_malloc(sizeof(void *) * this->capacity);
}