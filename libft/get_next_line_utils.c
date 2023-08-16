/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:21:50 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/18 13:14:20 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	if (!s)
// 		return (0);
// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strndup(const char *s1, size_t len)
// {
// 	char	*res;
// 	size_t	i;

// 	if (!s1)
// 		return (NULL);
// 	i = 0;
// 	res = (char *)malloc((len + 1) * sizeof(char));
// 	if (!res)
// 		return (NULL);
// 	while (i < len)
// 	{
// 		res[i] = s1[i];
// 		i++;
// 	}
// 	res[i] = '\0';
// 	return (res);
// }

// char	*ft_strjoin(const char *s1, const char *s2)
// {
// 	char	*res;
// 	char	*tmp;

// 	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!tmp)
// 		return (NULL);
// 	res = tmp;
// 	while (*s1)
// 		*(tmp++) = *(s1++);
// 	while (*s2)
// 		*(tmp++) = *(s2++);
// 	*tmp = '\0';
// 	return (res);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	if (!s)
// 		return (NULL);
// 	while (*(unsigned char *)s != (unsigned char)c)
// 	{
// 		if (*(unsigned char *)s == '\0')
// 			return (NULL);
// 		s++;
// 	}
// 	return ((char *)s);
// }

char	*ft_lst_del_node(t_gnl **head, t_gnl *cur)
{
	t_gnl	*tmp;

	if (*head == cur)
		*head = cur->next;
	else
	{
		tmp = *head;
		while (tmp->next != cur)
			tmp = tmp->next;
		tmp->next = cur->next;
	}
	free(cur->buf);
	free(cur);
	cur = NULL;
	return (NULL);
}
