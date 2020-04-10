/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:35:21 by hmellahi          #+#    #+#             */
/*   Updated: 2020/04/02 02:24:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int		ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	res;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] == '\t' || str[i] == '\r' || str[i] == ' ')
			|| (str[i] == '\v' || str[i] == '\n' || str[i] == '\f'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res * 10 > 9223372036854775807)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		res = res * 10 + (str[i++] - '0');
	}
	return (res * sign);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
		if (*s1++ != *s2++)
			return (*(unsigned char*)(s1 - 1) - *(unsigned char*)(s2 - 1));
	return (0);
}

void	ft_putchar(int c)
{
	write(1, &c,1);
}

void	ft_putstr(t_string str)
{
	write(1, str, ft_strlen(str));
}

char	*substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*substr;

	if (s == NULL)
		return (NULL);
	substr = (char*)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (len--)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}