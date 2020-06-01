/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:30:33 by wstygg            #+#    #+#             */
/*   Updated: 2020/06/01 17:33:06 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf_reader.h"
#include <stdlib.h>

int						main(void)
{
	const char			*path = "Conf.conf";
	t_list				*task_list;

	conf_help();
	if (!(task_list = conf_read(path)))
		return (1);
	print_tasks(task_list);
	task_list = conf_reload("Conf_2.conf", task_list);
	print_tasks(task_list);
	task_list_delete(task_list);
	exit(0);
}
