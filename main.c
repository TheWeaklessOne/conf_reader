/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:30:33 by wstygg            #+#    #+#             */
/*   Updated: 2020/06/02 00:03:48 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf_reader.h"
#include <stdlib.h>

int						main(void)
{
	const char			*path = "Conf.conf";
	t_list				*task_list;

	g_end_code = 0;
//	conf_help();
	task_list = conf_read(path);
	print_tasks(task_list);
	task_list = conf_reload("Conf_2.conf", task_list);
	print_tasks(task_list);
	task_list_delete(task_list);
	return (g_end_code);
}
