/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_reader.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 00:17:31 by wstygg            #+#    #+#             */
/*   Updated: 2020/06/01 23:57:55 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONF_READER_H
# define CONF_READER_H

# include "structures.h"

typedef	struct s_list	t_list;

unsigned char			g_end_code;

void					conf_help(void);
void					task_delete(t_task **task_p);
void					print_tasks(t_list *task_list);
void					task_list_delete(t_list *task_list);
t_list					*conf_read(const char *path);
t_list					*conf_reload(const char *path, t_list *old_tasks);

#endif
