/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 09:51:10 by hmellahi          #+#    #+#             */
/*   Updated: 2020/04/07 02:05:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_string	*init_errors()
{
	t_string	*messages;

	messages = sf_malloc(sizeof(char*) * 10);
	messages[0] = "Allocation Failed";
	messages[1] = "GETCWD Failed";
	messages[2] = "WTF ARE U TRYING TO DO BITCH\nUse help to get the available functions";
	messages[3] = "Syntax Error";
	messages[4] = "";
	messages[5] = "";
	messages[6] = "";
	return (messages);
}

void		handle_error(int error_index, int status)
{
	printf("%s\n", shell.errors[error_index]);
	free_all(status);
	//exit(status);
}