/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgelinet@student.42.fr <lgelinet>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:38:44 by lgelinet@st       #+#    #+#             */
/*   Updated: 2021/06/30 18:51:23 by lgelinet@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*new_lst(char *ptr)
{
	t_list	*ret;

	ret = malloc(sizeof(t_list));
	ret->next = NULL;
	ret->p = ft_strdup(ptr);
	return (ret);
}

int	add_front(t_list **l, void *ptr)
{
	t_list	*temp;
	t_list	*ret;

	ret = new_lst(ptr);
	temp = *l;
	while (temp && temp->next)
		temp = temp->next;
	if (!*l)
		*l = ret;
	else
		temp->next = ret;
	return (1);
}

int	lst_last(t_list *l)
{
	int		i;
	t_list	*temp;

	i = 0;
	if (!l)
		return (i);
	temp = l;
	while (++i && temp->next)
		temp = temp->next;
	return (i);
}

int	clear_lst(t_list **l)
{
	t_list	*temp;
	t_list	*temp2;

	if (!l)
		return (0);
	temp = *l;
	while (temp->next)
	{
		temp2 = temp;
		temp = temp->next;
		do_free(temp2->p);
		do_free(temp2);
	}
	do_free(temp->p);
	do_free(temp);
	l = NULL;
	return (1);
}
