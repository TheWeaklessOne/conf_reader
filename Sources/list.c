/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:30:15 by wstygg            #+#    #+#             */
/*   Updated: 2020/06/02 14:54:00 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list			*list_remove_front(t_list *list, int to_free)
{
	t_list		*ret;

	if (!list)
		return (NULL);
	ret = list->next;
	if (to_free)
		free(list->task);
	free(list);
	return (ret);
}

t_list			*list_remove_back(t_list *list, int to_free)
{
	t_list		*to_del;
	t_list		*ret;

	if (!list)
		return (NULL);
	if (!list->next)
	{
		if (to_free)
			free(list->task);
		free(list);
		return (NULL);
	}
	ret = list;
	while (list->next && list->next->next)
		list = list->next;
	to_del = list->next;
	if (to_free)
		free(to_del->task);
	free(to_del);
	list->next = NULL;
	return (ret);
}

t_list			*list_add_front(t_list *list, t_task *content)
{
	t_list		*item;

	if (!list)
		return (list_create(content));
	if (!(item = malloc(sizeof(t_list))))
		ft_crash("Malloc error");
	item->task = content;
	item->next = list;
	return (item);
}

t_list			*list_add_back(t_list *list, t_task *content)
{
	t_list		*item;
	t_list		*ret;

	if (!list)
		return (list_create(content));
	if (!content)
		return (list);
	ret = list;
	while (list->next)
		list = list->next;
	if (!(item = malloc(sizeof(t_list))))
		ft_crash("Malloc error");
	item->task = content;
	item->next = NULL;
	list->next = item;
	return (ret);
}

t_list			*list_create(t_task *content)
{
	t_list		*ret;

	if (!content)
		return (NULL);
	if (!(ret = malloc(sizeof(t_list))))
		ft_crash("Malloc error");
	ret->task = content;
	ret->next = NULL;
	return (ret);
}
