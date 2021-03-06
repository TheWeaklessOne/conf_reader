/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_job.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 12:40:09 by wstygg            #+#    #+#             */
/*   Updated: 2020/06/02 14:54:00 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

static void		fill_task_next_next(char **conf, int *i, t_task *task,
					int uniq[PARAMS_N])
{
	char		*str;

	str = skip_emptiness(conf[*i]);
	if (!strncmp(str, "success_waiting:", 16) &&
		uck(SUCCESS_WAITING, uniq, *i, conf[*i]))
		task->success_waiting = create_success_waiting(conf[*i], *i);
	else if (!strncmp(str, "end_codes:", 10) && uck(END_CODES, uniq,
			*i, conf[*i]))
		create_end_codes(task->end_codes, conf[*i], *i);
	else if (!strncmp(str, "env:", 4) && uck(ENV, uniq, *i, conf[*i]))
		create_env(task, conf, i);
	else
		ft_error("Error at [%d] line: %s\nUnknown keyword!\n",
				*i + 1, conf[*i]);
}

static void		fill_task_next(char **conf, int *i, t_task *task,
		int uniq[PARAMS_N])
{
	char		*str;

	str = skip_emptiness(conf[*i]);
	if (!strncmp(str, "restart:", 8) && uck(RESTART, uniq, *i,
			conf[*i]))
		task->restart = create_restart(conf[*i], *i);
	else if (!strncmp(str, "retries:", 8) && uck(RETRIES, uniq, *i,
			conf[*i]))
		task->retries = create_retries(conf[*i], *i);
	else if (!strncmp(str, "on_start:", 9) && uck(ON_START, uniq, *i,
			conf[*i]))
		task->on_start = create_on_start(conf[*i], *i);
	else if (!strncmp(str, "stop_signal:", 12) && uck(STOP_SIGNAL, uniq,
			*i, conf[*i]))
		task->stop_signal = create_stop_signal(conf[*i], *i);
	else if (!strncmp(str, "stop_waiting:", 13) && uck(STOP_WAITING,
			uniq, *i, conf[*i]))
		task->stop_waiting = create_stop_waiting(conf[*i], *i);
	else
		fill_task_next_next(conf, i, task, uniq);
}

static void		fill_task(char **conf, int *i, t_task *task,
		int uniq[PARAMS_N])
{
	char		*str;

	str = skip_emptiness(conf[*i]);
	if (tab_count(conf[*i]) != 1)
		ft_error("Error at [%d] line:\n%s\nThere have to be 1 tab depth before "
		"keyword!\n", *i + 1, conf[*i]);
	else if (!strchr(str, ':'))
		ft_error("Error at [%d] line: %s\nKeyword have to followed by ':' "
		"symbol!\n", *i + 1, conf[*i]);
	else if (!strncmp(str, "command:", 8) && uck(COMMAND, uniq, *i, conf[*i]))
		task->command = create_command(conf[*i], *i);
	else if (!strncmp(str, "directory:", 10) && uck(DIR, uniq, *i, conf[*i]))
		task->directory = create_directory(conf[*i], *i, task->directory);
	else if (!strncmp(str, "umask:", 6) && uck(UMASK, uniq, *i, conf[*i]))
		task->umask = create_umask(conf[*i], *i);
	else if (!strncmp(str, "copies:", 7) && uck(COPIES, uniq, *i, conf[*i]))
		task->copies = create_copies(conf[*i], *i);
	else if (!strncmp(str, "stdout:", 7) && uck(STDOUT, uniq, *i, conf[*i]))
		task->tstdout = create_stdout(conf[*i], *i);
	else if (!strncmp(str, "stderr:", 7) && uck(STDERR, uniq, *i, conf[*i]))
		task->tstderr = create_stderr(conf[*i], *i);
	else
		fill_task_next(conf, i, task, uniq);
}

static void		check_task(t_task **task_p)
{
	t_task		task;

	task = **task_p;
	if (!task.command)
	{
		ft_error("%s task is incomplete. Missing \"command\" "
				"field!\n", task.name);
		task_delete(task_p);
	}
}

t_task			*create_task(char **conf, int *i)
{
	t_task		*task;
	int			k;
	int			params_uniq[PARAMS_N];

	k = -1;
	while (++k < PARAMS_N)
		params_uniq[k] = 0;
	task = ft_malloc(sizeof(t_task));
	*task = (t_task)
	{
		.remake = 1, .umask = 18, .copies = 1, .tstdout = 1, .tstderr = 2,
		.restart = 2, .retries = 1, .on_start = 1, .stop_signal = 2,
		.stop_waiting = 5, .success_waiting = 10, .end_codes[0] = 0
	};
	task->directory = getcwd(NULL, 80);
	k = 0;
	while (++k < END_CODES_N)
		task->end_codes[k] = -1;
	if (!(task->name = create_name(conf[*i], *i)))
	{
		task_delete(&task);
		return (NULL);
	}
	while (!str_is_empty(conf[++(*i)]) && tab_count(conf[*i]) != 0)
		fill_task(conf, i, task, params_uniq);
	check_task(&task);
	(*i)--;
	return (task);
}
