/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 22:16:31 by hmellahi          #+#    #+#             */
/*   Updated: 2020/04/09 01:22:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	*sf_malloc(size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(size)))
		(handle_error(Allocation_Failed, FAIL));
	vector_push_back(&shell.adresses, ptr);
	return (ptr);
}

void	free_all()
{
	vector_free(&shell.adresses);
	printf("yees");
}
