/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 14:35:26 by marvin            #+#    #+#             */
/*   Updated: 2020/04/02 14:35:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

typedef struct s_lst
{
    void *content;
    struct s_lst *next;
}               t_lst;
// UTIL FUNCTIONS
int		ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *str);
char		*ft_strchr(const char *s, int c);
char		*join(char const *s1, char const *s2);
char		*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putchar(int c);
void	ft_putstr(t_string str);
char	*substr(char const *s, unsigned int start, size_t len);
char				**split(char const *s, char c);
int		tablen(void **tab);
// errors
t_string	*init_errors();
void		handle_error(int error_index, int status);
void	free_all();
// linked list
void	push_back(t_lst **alst, t_lst *new);
void	push_front(t_lst **head_ref, t_lst *new);
t_lst	*new_lst(void *content);
void	deletelist(t_lst **head_ref);
int		read_line(int fd, char **line);
void	*sf_malloc(size_t size);
#endif